void handle_integer(va_list args) {
    int i = va_arg(args, int);
    printf("%d", i);
}

void handle_char(va_list args) {
    char c = (char) va_arg(args, int);
    printf("%c", c);
}

void handle_string(va_list args) {
    char *s = va_arg(args, char *);
    printf("%s", s);
}
