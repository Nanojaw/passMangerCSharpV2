namespace passMangerCSharpV2 {
    internal class application {
        

        public static void run(bool existingProfile) {
            if (existingProfile) {
                mainLoop();
            }
            else {
                createProfile();
            }
        }
    }
}