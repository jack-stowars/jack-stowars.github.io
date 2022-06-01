# Professional Self-Assessment


# Preliminary Code Review
### [Artifact One (GAM-312 C++ Game Development C++)](https://youtu.be/8U0qmrQv15I)

### [Artifact Two (IT-312 C++ Dice Game)](https://youtu.be/0ZkTsT7tsH4)

### [Artifact Three (DAD-220 MySQL Database Final Project)](https://youtu.be/W5e7DDigQ0k)

# Artifact One (GAM-312 C++ Game Development) [Code Files](https://github.com/jack-stowars/jack-stowars.github.io/blob/175bf068362a1907709b7f42685e67b0245d9cff/ArtifactOne)

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
  ### New Version of camera change logic (lines 34-64 of Cameradirector.cpp)
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



# Artifact Two (IT-312 C++ Dice Game)
### Code

### Narrative


# Artifact Three (DAD-220 MySQL Database Final Project)
### Code

### Narrative






## Welcome to GitHub Pages

You can use the [editor on GitHub](https://github.com/jack-stowars/jack-stowars.github.io/edit/main/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/jack-stowars/jack-stowars.github.io/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
