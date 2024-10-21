package com.example.tranzact.auth.controllers;
import com.example.tranzact.auth.records.SignupRequest;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Onboarding {

//   @Autowired
//    private EmailService emailService;
//    @Autowired
//    private UserService userService; // Assuming you have a UserService for user operations

//    public Onboarding(EmailService emailService) {
//        this.emailService = emailService;
//    }

    @PostMapping("/auth/signup")
    public String signup(@ModelAttribute SignupRequest signupRequest) {
        System.out.print(signupRequest.email());

        String token = generateToken(); // Implement a method to generate a unique token

        System.out.print(token);
        return "signup-success"; // Redirect to a success page or show a message
    }

//    @GetMapping("/auth/verify-email")
//    public String verifyEmail(@RequestParam String token) {
//        if (isValidToken(token)) { // Implement a method to validate the token
//            // Mark the user as verified in your database
//            // Redirect to the complete signup page or show a success message
//            return "complete-signup";
//        } else {
//            return "invalid-token"; // Handle invalid token
//        }
//    }
//
//    @PostMapping("/auth/complete-signup")
//    public String completeSignup(@ModelAttribute SignupRequest signupRequest, @RequestParam String token) {
//        if (isValidToken(token)) {
//            // Create a new user model with the provided information
//            User user = new User(signupRequest.getFirstName(), signupRequest.getLastName(), signupRequest.getEmail());
//            userService.createUser(user);
//
//            return "signup-complete"; // Redirect to a complete signup page or show a success message
//        } else {
//            return "invalid-token"; // Handle invalid token
//        }
//    }

    // Implement methods to generate and validate tokens
    private String generateToken() {
        // Your token generation logic here
        return "your_generated_token";
    }

    private boolean isValidToken(String token) {
        // Your token validation logic here
        return true; // Replace with actual validation
    }
}
