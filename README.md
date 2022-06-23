## Alon tasks

# How to run?
1. Install the VSCode extension "Remote-Containers" by Microsoft.
2. Command Palette => Remote-Containers: Clone repository in a container volume
3. Wait for the image to be build and container to be started.
4. Run the selected file with the built-in debugger of VSCode.

# Links for tasks
Links for the tasks (these links will contain information about how to test the algorithms):
1. [weird algorithm](https://cses.fi/alon/task/1068)
2. [increasing array](https://cses.fi/alon/task/1094)
3. [two sets](https://cses.fi/alon/task/1092)

# Notes
Test file for inputs:
1. Add the txt-file inside the task folder.
2. Edit the args in the launch.json to be the following: ```"args": ["<", "${workspaceFolder}/${____FOLDER_NAME_____}/test_input.txt"]```
