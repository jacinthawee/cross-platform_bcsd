
undefined4 ssl_ctx_make_profiles(char *param_1,_STACK **param_2)

{
  _STACK *st;
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  char *__s;
  undefined **data;
  size_t __n;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x14,0x135,0x16a,"d1_srtp.c",0xc9);
    return 1;
  }
  pcVar1 = strchr(param_1,0x3a);
  if (pcVar1 == (char *)0x0) goto LAB_0005faee;
LAB_0005fa9c:
  __n = (int)pcVar1 - (int)param_1;
  __s = srtp_known_profiles;
  do {
    srtp_known_profiles = __s;
    if (__s == (char *)0x0) {
LAB_0005fafe:
      ERR_put_error(0x14,0x135,0x16c,"d1_srtp.c",0xd8);
      return 1;
    }
    data = &srtp_known_profiles;
    while ((sVar2 = strlen(__s), __n != sVar2 || (iVar3 = strncmp(__s,param_1,__n), iVar3 != 0))) {
      data = data + 2;
      __s = *data;
      if (__s == (char *)0x0) goto LAB_0005fafe;
    }
    sk_push(st,data);
    if (pcVar1 == (char *)0x0) {
      *param_2 = st;
      return 0;
    }
    param_1 = pcVar1 + 1;
    pcVar1 = strchr(param_1,0x3a);
    if (pcVar1 != (char *)0x0) goto LAB_0005fa9c;
LAB_0005faee:
    __n = strlen(param_1);
    __s = srtp_known_profiles;
  } while( true );
}

