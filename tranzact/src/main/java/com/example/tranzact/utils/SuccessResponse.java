package com.example.tranzact.utils;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

public class SuccessResponse {
    private final ApiResponse response;

    public SuccessResponse(String message, Object content) {
        this.response = new ApiResponse(true, message, content);
    }

    public ResponseEntity<ApiResponse> send() {
        return new ResponseEntity<>(this.response, HttpStatus.OK);
    }
}