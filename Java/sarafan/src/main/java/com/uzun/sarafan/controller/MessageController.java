package com.uzun.sarafan.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("message")//Все обращения на сайт со ссловом message будут направлятся на MessageController
public class MessageController {
    @GetMapping
    public  String list() {
        return "index";
    }
}
