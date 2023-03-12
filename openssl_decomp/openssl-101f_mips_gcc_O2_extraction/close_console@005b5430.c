
undefined4 close_console(void)

{
  if (tty_in != *(int *)PTR_stdin_006aab20) {
    (*(code *)PTR_fclose_006aaaa4)();
  }
  if (tty_out != *(int *)PTR_stderr_006aac00) {
    (*(code *)PTR_fclose_006aaaa4)();
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1f,"ui_openssl.c",0x246);
  return 1;
}

