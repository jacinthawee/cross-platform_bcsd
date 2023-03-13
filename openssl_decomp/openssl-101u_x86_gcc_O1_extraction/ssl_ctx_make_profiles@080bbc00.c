
undefined4 __regparm3 ssl_ctx_make_profiles(char *param_1,_STACK **param_2)

{
  _STACK *st;
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  undefined1 *data;
  char *__s;
  size_t __n;
  int line;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x14,0x135,0x16a,"d1_srtp.c",0xb1);
    return 1;
  }
  do {
    pcVar1 = strchr(param_1,0x3a);
    if (pcVar1 == (char *)0x0) {
      __n = strlen(param_1);
    }
    else {
      __n = (int)pcVar1 - (int)param_1;
    }
    if (srtp_known_profiles._0_4_ == (char *)0x0) {
LAB_080bbcc0:
      line = 0xc4;
      iVar3 = 0x16c;
LAB_080bbcd2:
      ERR_put_error(0x14,0x135,iVar3,"d1_srtp.c",line);
      sk_free(st);
      return 1;
    }
    data = srtp_known_profiles;
    __s = srtp_known_profiles._0_4_;
    while ((sVar2 = strlen(__s), __n != sVar2 || (iVar3 = strncmp(__s,param_1,__n), iVar3 != 0))) {
      data = (undefined1 *)((int)data + 8);
      __s = *(char **)data;
      if (__s == (char *)0x0) goto LAB_080bbcc0;
    }
    iVar3 = sk_find(st,data);
    if (-1 < iVar3) {
      line = 0xbc;
      iVar3 = 0x161;
      goto LAB_080bbcd2;
    }
    sk_push(st,data);
    if (pcVar1 == (char *)0x0) {
      *param_2 = st;
      return 0;
    }
    param_1 = pcVar1 + 1;
  } while( true );
}

