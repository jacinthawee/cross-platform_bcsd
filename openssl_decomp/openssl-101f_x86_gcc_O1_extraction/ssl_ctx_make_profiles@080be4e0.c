
undefined4 __regparm3 ssl_ctx_make_profiles(char *param_1,_STACK **param_2)

{
  _STACK *st;
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  size_t __n;
  char *__s;
  undefined1 *data;
  int line;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    line = 0xc9;
    iVar3 = 0x16a;
LAB_080be592:
    ERR_put_error(0x14,0x135,iVar3,"d1_srtp.c",line);
    return 1;
  }
LAB_080be500:
  pcVar1 = strchr(param_1,0x3a);
  if (pcVar1 == (char *)0x0) {
    __n = strlen(param_1);
  }
  else {
    __n = (int)pcVar1 - (int)param_1;
  }
  if (srtp_known_profiles._0_4_ != (char *)0x0) {
    data = srtp_known_profiles;
    __s = srtp_known_profiles._0_4_;
    do {
      sVar2 = strlen(__s);
      if (__n == sVar2) {
        iVar3 = strncmp(__s,param_1,__n);
        if (iVar3 == 0) goto code_r0x080be55b;
      }
      data = (undefined1 *)((int)data + 8);
      __s = *(char **)data;
      if (__s == (char *)0x0) break;
    } while( true );
  }
  line = 0xd8;
  iVar3 = 0x16c;
  goto LAB_080be592;
code_r0x080be55b:
  sk_push(st,data);
  if (pcVar1 == (char *)0x0) {
    *param_2 = st;
    return 0;
  }
  param_1 = pcVar1 + 1;
  goto LAB_080be500;
}

