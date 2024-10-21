package com.example.tranzact.utils;

import lombok.Getter;
import org.springframework.http.HttpStatus;

@Getter
public class CustomException extends Exception {
    private final String message;
    private final Object content;
    private final HttpStatus statusCode;

    public CustomException(String message, Object content, HttpStatus statusCode) {
        super(message);
        this.message = message;
        this.content = content;
        this.statusCode = statusCode;
    }
}