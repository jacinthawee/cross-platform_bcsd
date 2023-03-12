
undefined4 generate_session_id(SSL *param_1,uchar *param_2,uint *param_3)

{
  char *__src;
  int iVar1;
  size_t sVar2;
  uint __n;
  int iVar3;
  
  iVar3 = 10;
  while( true ) {
    iVar1 = RAND_bytes(param_2,*param_3);
    __src = session_id_prefix;
    if (iVar1 < 1) {
      return 0;
    }
    sVar2 = strlen(session_id_prefix);
    __n = *param_3;
    if (sVar2 <= *param_3) {
      __n = sVar2;
    }
    memcpy(param_2,__src,__n);
    iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3);
    if (iVar1 == 0) break;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  return 1;
}

