# Professional Self-Assessment
The completion of my coursework throughout my computer science program, as well as the artifacts showcased in this ePortfolio, have helped to showcase several of my strengths in the industry. 

- **Team Collaboration:** For the duration of my GAM-305 course (which was not one of my chosen artifacts), I had the opportunity to take a course that allowed for me to work in a team with other fellow computer science/game development majors. Throughout the duration of the course, me and 3 other classmates were to develop a video game of our own design using Unreal Engine, while also documenting and keeping track of how work was distributed and how we worked as a team. By taking this course, I was not only able to take another course that involved game development, but I was also able to get experience with working as a team with other people, as well as all of the pros and cons that can come with it. I learned many valuable team-based skills from that course, such as knowing how to compromise, assigning tasks while taking into account people's strengths and weaknesses, keeping to a schedule to meet a deadline, and to work with Git to be able to remotely work on the same project together.
- **Stakeholder Communication:** Once again, my GAM-305 course did a great job of giving me some practice with communicating with teammates, as well as hypothetical "stakeholders" for the course's project. For the duration of the group work in that course, we had to keep weekly logs of what we planned to do, how we divided up the work, how it ended up, and what (if anything) we learned for subsequent weeks. Through this process, it basically taught me how to contribute to a report that could be given to superiors or other stakeholders in the company. This can also be said for the improvements to the in-line commenting that I did for my artifact, as it would make it easier for an outside party to be able to pick up what I've worked on and make changes, as the comments that I added explained the core functionality of each function, a swell as what each relevant section of the function and code in general did.
- **Data Structures & Algorithms:** Artifact two in my ePortfolio was what I chose to demonstrate my skills with data structures & algorithms, as it was a course where we were tasked with choosing from a list of games and create them using C++. Since games tend to involve a lot of logic checks and data reading/writing, as well as it being one of the coding assignments I was most proud of, I saw this artifact as the perfect means to demonstrate my ability to utilize algorithms and data structures in an efficient and functioning way. The game that I created for that particular artifact was "Left Right Center", and it required quite a bit of structuring to get it to work. For example, the game needed to be able to keep track of which player's turn it was currently so that, if chips were to be passed left or right, the function that was made to pass chips would pass them to the proper player. 
- **Software Engineering:** Artifact one in my ePortfolio was what I chose to demonstrate my skills with software engineering, as it was a course dedicated entirely to creating gameplay elements from scratch using C++ classes instead of Unreal Engine blueprints. The reason for choosing this particular artifact was solely due to the fact that it was a game development course, as I had several other artifacts from various other courses I could've selected for this demonstration. Since I am looking to get a job in the field of game development, I decided that using an artifact that involved game development would be the most ideal choice to make, as it would demonstrate both my software engineering skills and game development skills in the same artifact. 
- **Security:** While I don't have the most experience with security-based design choices, I understand the importance of them and how they can be a major factor in the path of development for any given company. The extent of my security implementations was from a very early Java course I had taken, where we had to implement a hash table into a simulated login system in order to access data based on who had logged into the system. While it wasn't a massive undertaking, it did give me a good insight into how important security measures can be, since they can cause serious issues such as users being unable to access the software or not properly saving data where it is supposed to be saved at. Since video games (especially online video games) involve security measures to ensure that nobody is able to maliciously access your game data, security would end up being a very relevant part of any job opportunity.

# Preliminary Code Review
### [Artifact One (GAM-312 C++ Game Development)](https://youtu.be/8U0qmrQv15I)

### [Artifact Two (IT-312 C++ Dice Game)](https://youtu.be/0ZkTsT7tsH4)

### [Artifact Three (DAD-220 MySQL Database Final Project)](https://youtu.be/W5e7DDigQ0k)

# Artifact One (GAM-312 C++ Game Development) [Code Files](https://github.com/jack-stowars/jack-stowars.github.io/tree/main/ArtifactOne)

The first artifact that I will be using for my ePortfolio is my final project submission for my GAM-312 course last term. It is a project whose purpose was to teach students to make a game using Unreal Engine. However, instead of using blueprints, which is the typical means by which games are made using Unreal Engine, the project had to be made using C++ classes, which is basically writing everything from scratch using a coding environment instead of a blueprint editor. 
	
The reason for the inclusion of this artifact over others is that it demonstrates my ability to use the class development tool in Unreal Engine as opposed to the blueprint editor. Since the blueprint editor is a lot more user friendly compared to C++ classes, demonstrating my ability to use the classes means that I have the capacity to both use blueprints and classes. From what I have heard regarding blueprints, they are typically the go-to method of development, but classes are used on occasion depending on the complexity of the component being created, as the blueprint editor can get very cluttered very quickly and become a tangled mess.
	
I would say that the course objectives were met with this enhancement, as I ultimately improved two critical areas of my project. The first critical area is the camera director, which originally didn’t have a toggle option and just took over the camera from the game starting. 
  
### Original version of camera change logic
  ```
  if (OurPlayerController)
		{

			//If the player controller's current camera is not camera one and camera two is not null
			if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
			{
				//Smoothly blends camera view to camera one
				OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
			}

			//If the player controller's current camera is not camera two and camera two is not null
			else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
			{
				//Smoothly blends camera view to camera two
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
		}
  ```
### New version of camera change logic (lines 34-64 of Cameradirector.cpp)
  ```
  if (cameraChange) 
	{

		if (TimeToNextCameraChange <= 0.0f) {
			TimeToNextCameraChange += TimeBetweenCameraChange;

			// Establishes a pointer to the player controller for camera switching
			APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

			// Functions will run if player controller is found, otherwise does not run
			if (OurPlayerController) {

				// If current camera is CameraOne, swaps to CameraTwo
				if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne)) {
					OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
				}

				// If current camera is CameraTwo, swaps to CameraOne
				else if (CameraOne) {
					OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
				}
			}
		}

		// Runs when camera finishes swapping to reset cameraToggle function and relevant variables
		else {
			cameraChange = false;
			TimeToNextCameraChange = 0.0f;
		}
	}
}
  ```
  
  Adding in the toggle option removed this issue, as the player now has the control to enable or disable the camera cycling at will. The second critical area is the in-line commenting, as reviewing my code has made me realize that my comments could be more in-depth, such as describing what certain functions do when they are declared. This way, someone else who would potentially be looking at my project would have a better idea of how the functions work, as it would clearly explain what each component in the function is and what it is used for.
	
  Through creating the enhancements to the project, I got a better understanding of how to bind controls through the Unreal Editor, as well as how to properly make use of them in the class files. Through completing this enhancement, I also learned how to declare outside functions from the player controller, which is a very powerful tool to enhance gameplay mechanics and allow the player to be able to interact with things outside of their own class file. There weren’t too many challenges when performing these enhancements, as in-depth commenting was relatively easy to complete, and the toggle option was done by altering the already functional code to make it a toggle function instead of it happening at set intervals.



# Artifact Two (IT-312 C++ Dice Game) [Code Files](https://github.com/jack-stowars/jack-stowars.github.io/tree/main/ArtifactTwo)

The second artifact is a dice game that I completed during my IT-312 class, and this will be demonstrating my skills with algorithms & data structures. I chose to include this artifact due to it being a program that I made from the ground-up for my class, as well as it being heavily reliant on algorithmic operations to function. Since this particular dice game has a lot of conditional functionality (number of players, number of chips each player has, etc.), I found that the inclusion of this specific artifact was a great way to showcase this skill.

The enhancements I had planned were adequately met in my actual enhancement of this artifact. In the code review, I discussed how certain chunks of code could be slimmed down, such as several “if” statements being nested into a single “for” loop, as well as how I had left out commenting for an entire relevant section of the code. With those two enhancements to the artifact, the code would be more compact/efficient, as well as more understandable for someone else looking at my code, as the lack of commenting could make it more difficult to read through.
	
### Original version of dice rolling logic
```
int *RollDice(int chips[], int turn, int players) {
        srand(time(0));

        int diceRolls[3] = {0,0,0};
        int j;


        if (chips[turn] == 0) {
            cout << "Player " << turn + 1 << " has no chips, moving to next player." << endl;
            return chips;
        }

        else if (chips[turn] == 1) {
            diceRolls[0] = rand() % 6 + 1;
        }

        else if (chips[turn] == 2) {
            diceRolls[0] = rand() % 6 + 1;
            diceRolls[1] = rand() % 6 + 1;
        }

        else {
            diceRolls[0] = rand() % 6 + 1;
            diceRolls[1] = rand() % 6 + 1;
            diceRolls[2] = rand() % 6 + 1;
        }
```

### New version of dice rolling logic (lines 203-247 of 7-1 Dice Game.cpp)
```
    /* Function that rolls dice for each's players turn
    *  chips[] is array of current player's chip count
    *  turn is used to get chips from current turn's player to roll proper amount of dice
    *  players is used to properly distribute chips for players at the beginning/end of chips[] array
    */
    int *RollDice(int chips[], int turn, int players) {
        srand(time(0));

        /* 
        *  diceRolls[] stores rolls for each turn, resets to 0 every iteration
        *  rollCount is used to prevent more than 3 rolls per turn
        *  j is used in "for" loop to move chips based on rolls
        *  k is used in "for" loop to roll dice
        */

        int diceRolls[3] = {0,0,0};
        int rollCount;
        int j;
        int k;


        // If current player has 0 chips, does not roll dice and passes turn to next player
        if (chips[turn] == 0) {
            cout << "Player " << turn + 1 << " has no chips, moving to next player." << endl;
            return chips;
        }

        // If current player has 1 or more chips, initiates the dice rolling functionality
        else if (chips[turn] >= 1) {

            // Assigns 3 to rollCount if current player's chip count is greater than 3 to prevent errors
            if (chips[turn] > 3) {
                rollCount = 3;
            }

            // Assigns current chip count to rollCount in current player's chip count is 3 or less
            else {
                rollCount = chips[turn];
            }

            // Rolls dice for each iteration and assigns results to diceRolls[] array
            for (k = 0; k < rollCount; ++k) {
                diceRolls[k] = rand() % 6 + 1;
            }
        }
```

One major lesson that I learned while making these enhancements is how to look for potential situations where code can be compacted efficiently, such as where a “for” loop could be utilized in place of “if” statements. For example, in the code for the dice game, there were three different “if” statements that would run dice rolls based on how many chips the player had. In this situation, all 3 of the “if” statements were combined into one single “for” loop that would run X amount of times, where X is the amount of chips the current player has and X must be between 1 and 3. Otherwise, the loop would not run, since 0 rolls would be unnecessary and any more than 3 rolls would be useless to the game, as there can only be a maximum of 3 dice rolls. I also added in a bunch of relevant comments throughout the entirety of the file, as the entire RollDice function didn't have any commenting whatsoever in the first drafting of the coding assignment.


# Artifact Three (DAD-220 MySQL Database Final Project) [Code Files](https://github.com/jack-stowars/jack-stowars.github.io/tree/main/ArtifactThree)
The third artifact that I chose was my final project submission for my DAT-220 class, which revolved around learning and utilizing MySQL to navigate and modify databases. The primary reason that I decided to choose this artifact was because it was the best out of the few that I had to demonstrate my skills with databases. Since database skills aren’t of the highest of importance when being a game developer (unless you’re specifically working with the data aspect of the game), I only took the database courses that were required for the degree. When it came to electives, I chose classes that would be more universally beneficial to me in the game development field, such as classes based on C++ coding and/or utilization of Unreal Engine.

Since the course work was in an isolated development environment I no longer have access to, I am unable to create proper enhancements for this particular artifact. However, I still wanted to be able to demonstrate what skills I do have with database management, even though the desired field I’m looking to work in would have little use for it. This is also because database skills were not going to be the focal point/strength of my portfolio, but rather the software design and algorithm-based skills that were displayed in the first two artifacts.

### Adding data into MySQL table
![Task 1](https://user-images.githubusercontent.com/79537018/173445715-8a449f3d-44dd-4a3a-b3a7-b221cde9d60d.png)


### Altering MySQL table structure
![Task 2](https://user-images.githubusercontent.com/79537018/173445795-c74a70f2-074e-42c8-ac88-94b7d05c5cc8.png)


### Updating MySQL table data based on specific query
![Task 7](https://user-images.githubusercontent.com/79537018/173445922-d871e8ff-adef-4dad-b2f7-daf8dc73702d.png)
