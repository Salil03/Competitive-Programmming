import urllib
import os
import re
import sys

# Keep track of the last opened program
last_url = ''

# Load the settings file, ideally this should be called once and only once


# The main folder where the folder of the current program should be created
def get_parent_dir():
    return os.path.join("/home/salil/Documents/Competitive-Programmming/Programs/C++/Codeforces")


def get_codechef_dir():
    return os.path.join("/home/salil/Documents/Competitive-Programmming/Programs/C++/CodeChef")


def get_spoj_dir():
    return os.path.join("/home/salil/Documents/Competitive-Programmming/Programs/C++/SPOJ")


def get_vjudge_dir():
    return os.path.join("/home/salil/Documents/Competitive-Programmming/Programs/C++/Virtual_judge")


# Get the extensions of the file
def get_extension():
    return "cpp"


def change_url(filename):
    with open(filename, 'r') as new_file:
        filedata = new_file.read()
    filedata = filedata.replace("url", last_url)
    with open(filename, 'w') as new_file:
        new_file.write(filedata)

# Create the program file
# TODO: make this method not dependent on any programming language


def createFile(dir_path, title, extension, codechef_directory, spoj_directory, vjudge_directory):
    os.makedirs(dir_path, mode=0o777, exist_ok=True)
    if "codechef" in last_url:
        try:
            filename = os.path.join(codechef_directory, str(re.findall(
                r'[A-Z]+', last_url)[-1]) + str(re.findall(r'\d+', last_url)[-1]) + '.' + extension)
        except IndexError:
            filename = os.path.join(codechef_directory, str(
                re.findall(r'[A-Z]+', last_url)[-1]) + '.' + extension)
    elif "spoj" in last_url:
        try:
            filename = os.path.join(spoj_directory, str(re.findall(
                r'[A-Z]+', last_url)[-1]) + str(re.findall(r'\d+', last_url)[-1]) + '.' + extension)
        except IndexError:
            filename = os.path.join(spoj_directory, str(
                re.findall(r'[A-Z]+', last_url)[-1]) + '.' + extension)
    elif "vjudge" in last_url:
        try:
            filename = os.path.join(vjudge_directory, str(re.findall(
                r'[A-Z]+', last_url)[-1]) + "_" + str(re.findall(r'\d+', last_url)[-1]) + '.' + extension)
        except IndexError:
            filename = os.path.join(vjudge_directory, str(
                re.findall(r'[A-Z]+', last_url)[-1]) + '.' + extension)
    else:
        filename = os.path.join(dir_path, title + "_" + str(re.findall(r'\d+', last_url)[
                                0]) + str(re.findall(r'[A-Z]', last_url)[0]) + '.' + extension)
    try:
        open(filename, "a").close()
        os.system("code " + filename)
        return filename
    except Exception as e:
        print("Exception: ", e)
        return None


# Extract the title of the program
def get_title(url):
    from bs4 import BeautifulSoup
    global last_url
    last_url = url
    if "codechef" in last_url or "spoj" in last_url or "vjudge" in last_url:
        return ""
    try:
        reponse = urllib.urlopen(url)
    except Exception as e:
        print(e)
        return
    page = reponse.read()
    soup = BeautifulSoup(page, 'html.parser')
    title = soup.find('div', attrs={'class': 'problem-statement'}
                      ).find('div', attrs={'class': 'title'}).text[2:].strip()
    title = re.sub(r'[^\w]+', '_', title)
    return title


# Fetch the program using bs
def fetch(url):
    if url is None or url.strip() == '':
        return
    title = get_title(url)
    dir_path = get_parent_dir()
    extension = get_extension()
    codechef_directory = get_codechef_dir()
    spoj_directory = get_spoj_dir()
    vjudge_directory = get_vjudge_dir()
    file = createFile(dir_path, title, extension,
                      codechef_directory, spoj_directory, vjudge_directory)

    if file is None:
        return

    snippets_file_name = "/home/salil/Documents/Competitive-Programmming/Programs/C++/cpp.snippets"
    snippets_content = ''
    if snippets_file_name is not None:
        with open(snippets_file_name) as snippets_file:
            try:
                snippets_content = snippets_file.readlines()
                snippets_file.close()
            except FileNotFoundError:
                snippets_file.close()
                return

    with open(file, 'w') as newfile:
        newfile.writelines(snippets_content)
    change_url(file)
    return file


fetch(input("Enter url: "))