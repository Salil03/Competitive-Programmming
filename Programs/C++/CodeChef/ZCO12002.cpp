#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


struct exam
{
    int starttime;
    int endtime;
};


bool examcompare(exam lhs, exam rhs)
{
    return lhs.starttime<rhs.starttime;
};

int main()
{

    long long int counter=0, noofleave=0, noofreturn=0, noofexams=0, bestleave=0, bestreturn=0, trip=0, besttrip=99999999;

    cin>>noofexams>>noofleave>>noofreturn;

    long int leavearray[noofleave], returnarray[noofreturn];
    exam examarray[noofexams];



    for(counter=0; counter<noofexams; counter++)
    {
        cin>>examarray[counter].starttime>>examarray[counter].endtime;
    }

    for(counter=0; counter<noofleave; counter++)
    {
        cin>>leavearray[counter];
    }

    for(counter=0; counter<noofreturn; counter++)
    {
        cin>>returnarray[counter];
    }


    sort(examarray, examarray+noofexams, examcompare);

    sort(leavearray, leavearray+noofleave);

    sort(returnarray, returnarray+noofreturn);

    long int low=0, high=0, mid=0;

    for(counter=0; counter<noofexams; counter++)
    {
        if(leavearray[0]>examarray[counter].starttime)
        {
            continue;
        }

        else if(leavearray[noofleave-1]<=examarray[counter].starttime)
        {
            bestleave=leavearray[noofleave-1];
        }

        else
        {
            low=0;
            high=noofleave-1;

            while(low!=high)
            {
                mid=(high+low)/2;

                if(leavearray[mid]<=examarray[counter].starttime)
                {
                    low=mid+1;
                }

                else
                {
                    high=mid;
                }

            }

            bestleave=leavearray[high-1];
        }

        if(returnarray[noofreturn-1]<examarray[counter].endtime)
        {
            continue;
        }

        else if(returnarray[noofreturn-1]==examarray[counter].endtime)
        {
            bestreturn=returnarray[noofreturn-1];
        }

        else
        {
            low=0;
            high=noofreturn-1;

            while(low!=high)
            {
                mid=(high+low)/2;

                if(returnarray[mid]<=examarray[counter].endtime)
                {
                    low=mid+1;
                }

                else
                {
                    high=mid;
                }

            }

            if(returnarray[high-1]==examarray[counter].endtime)
            {
                bestreturn=returnarray[high-1];
            }

            else
            {
                bestreturn=returnarray[high];
            }

        }

        trip=(bestreturn-bestleave)+1;

        if(trip<besttrip)
        {
            besttrip=trip;
        }

    }


cout<<besttrip;

    return 0;
    }