package com.example.tranzact.utils;

import org.springframework.http.HttpStatus;

public class StatusExceptions {
    public static class BadRequestException extends CustomException {
        public BadRequestException(String message, Object content) {
            super(message, content, HttpStatus.BAD_REQUEST);
        }
    }

    public static class BadGateWayException extends CustomException {
        public BadGateWayException(String message, Object content) {
            super(message, content, HttpStatus.BAD_GATEWAY);
        }
    }

    public static class NotFoundException extends CustomException {
        public NotFoundException(String message, Object content) {
            super(message, content, HttpStatus.BAD_GATEWAY);
        }
    }
}
