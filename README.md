<b>MEC Review Project</b><br>
<b>CSC 212</b>

<b>Group Members:</b><br> 
Tyler Simonenko<br>
Nick Marshall<br>
Darryl Fleurantin<br>
Chun Wen<br>

<b>Summary:</b> <br>
As a student in college, knowing your current standing in a class is important. Being able to calculate your current grade will help you know how to proceed in the course - if you're doing well, you can feel confident about your study habits and the subject matter. If you're doing poorly, it may be wise to seek help to try and develop your understanding of the subject more. One of the reasons knowing your current standing is important is to determine how you may need to score on an upcoming assignment to receive a certain grade in the class. For example, if a student has completed all assignments, labs, and projects for a class, but the final exam remains, it would be useful for the student to know what score they needed to, pass the class or receieve an "A".

The MEC Review Project allows students to build a tool which allows them to calculate their current standing for a class. For this specific project, the class grade that will be calculated will be for CSC 212. Using the structures and methods introduced within CSC 211, students are required to provide an algorithm that will provide an accurate current standing based on the specific weights and assignments that are required within CSC 212.


<b>Preliminary Notes Document:</b><br>
[MEC Review Project Notes](https://github.com/TylerSimonenko/CSC_212_Review_Project/files/9883488/MEC.Review.Project.Notes.pdf)


<b>Preliminary Whiteboard Sketch:</b><br>
[MEC Planning](https://user-images.githubusercontent.com/68083538/198410520-940a4e30-887f-4d0b-9d44-dc6343940cc2.jpg)


<b>GitHub Repo Address:</b><br>
https://github.com/TylerSimonenko/CSC_212_Review_Project


<b>Algorithm Features and Description:</b><br>
Our algorithm first asks the user for the number of assignments and labs (as an integer) that have been completed and graded. Next, they will be asked if they have completed the review project, final project, and the final exam. The algorithm will limit the user to only valid inputs (for example, there are a max of 10 labs, 5 assignments, 1 exam, etc.) Once this data is gathered, the algorithm will ask the user to input the grade percentage that they received for each of the graded submissions (as a double) - the user will only be asked to provide as many grades as previously determined. The grade percentages must be calculated by the user. This is important because the algorithm will expect a grade value between 0-100, rather than asking for a point value which can range for some graded submissions. Calculations are done according to this.


The output of the code is a single line within the command line. The algorithm will output your calculated grade percentage and also display your letter grade for the class.


The development of the group's code was methodic and deliberate. We thought it was important to understand each step of the calculations first before tackling the main goal of the code (including the exceptions). At first, we made sure the calculations were correct for the case in which the student had completed each and every graded submission (this case would be the student's final grade for the entire class, not just the student's current standing). Once we understood the process for that case, we were able to work backwords and handle the exceptions, which were when the student had not yet completed certain assignments, labs, exams, or projects. In this case, each graded submission would be weighted differently as compared to the case in which every submission was completed. Working through each step with pseudocode and whiteboards helped us to make sure we accounted for each required detail. 


<b>Instructions:</b><br>
To run the algorithm, first you must download the main.cpp file and its dependencies (gradebook.h and gradebook.cpp). Once the main.cpp file is compiled (there are no necessary command line arguments), the user will be asked to input their information/data (which includes the number of completed assignments/labs, whether or not the exam and projects have been completed, and their specific earned grades). This grade information, again, must be in a percentage, rather than a point value. For example, a perfect %100 grade on the Term Project (worth 350 points) should be input as "100" rather than "350". The user can simply input their data and then press enter - there is no specific syntax or sentence structure to be used. Once the user is guided through each step of the data gathering process, the algorithm will provide the user with their grade in percentage form and in letter form in the output line. 
