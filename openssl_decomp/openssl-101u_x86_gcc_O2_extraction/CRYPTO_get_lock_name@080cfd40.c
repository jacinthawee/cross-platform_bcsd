
char * CRYPTO_get_lock_name(int type)

{
  int iVar1;
  char *pcVar2;
  
  if (type < 0) {
    return "dynamic";
  }
  if (type < 0x29) {
    pcVar2 = *(char **)(lock_names + type * 4);
  }
  else {
    iVar1 = sk_num(app_locks);
    pcVar2 = "ERROR";
    if (type + -0x29 <= iVar1) {
      pcVar2 = (char *)sk_value(app_locks,type + -0x29);
      return pcVar2;
    }
  }
  return pcVar2;
}

