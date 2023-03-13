
undefined4 close_console(void)

{
  FILE *mode;
  
  if (tty_in != stdin) {
    fclose(tty_in);
  }
  mode = tty_out;
  if (tty_out != stderr) {
    mode = (FILE *)fclose(tty_out);
  }
  CRYPTO_lock((int)mode,10,(char *)0x1f,(int)"ui_openssl.c");
  return 1;
}

