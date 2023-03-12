
undefined4 close_console(void)

{
  if (tty_in != *(int *)PTR_stdin_006a9a14) {
    (*(code *)PTR_fclose_006a9998)();
  }
  if (tty_out != *(int *)PTR_stderr_006a9af8) {
    (*(code *)PTR_fclose_006a9998)();
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1f,"ui_openssl.c",0x249);
  return 1;
}

