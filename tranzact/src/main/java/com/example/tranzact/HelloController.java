package com.example.tranzact;

import com.example.tranzact.utils.ApiResponse;
import com.example.tranzact.utils.SuccessResponse;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/")
    public ResponseEntity<ApiResponse> hello() throws Exception {
        return new SuccessResponse("App is running on port 8080", null).send();
    }

}