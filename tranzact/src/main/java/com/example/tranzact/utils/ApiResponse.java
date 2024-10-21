package com.example.tranzact.utils;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public class ApiResponse {
    // Getters and setters for success and message
    private Boolean success;
    private String message;
    // Getter and setter for content
    private Object content;

    public ApiResponse(Boolean success, String message, Object content) {
        setSuccess(success);
        setMessage(message);
        setContent(content);
    }

}