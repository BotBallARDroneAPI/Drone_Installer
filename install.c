void main()
{
	printf("CBC Drone Installer\n");
	printf("Press A to install.\n");
	
	while(! a_button()) msleep(5);
	while( a_button()) msleep(5);
	
	printf("Installing part 1...\n");

	system("/mnt/browser/usb/drone_installer/install1.sh");

	printf("Part 1 installed.  Press A to replace cbcui.  When finished, cbcui will reboot.");

	while(! a_button()) msleep(5);
	while( a_button()) msleep(5);
	
	printf("Installing cbcui...\n");

	sleep(3);

	system("/mnt/browser/usb/drone_installer/install2.sh");

}
