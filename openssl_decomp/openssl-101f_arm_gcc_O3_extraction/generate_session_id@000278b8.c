
undefined4 generate_session_id(SSL *param_1,uchar *param_2,uint *param_3)

{
  char *__src;
  size_t sVar1;
  int iVar2;
  uint __n;
  int iVar3;
  
  iVar3 = 10;
  while( true ) {
    RAND_pseudo_bytes(param_2,*param_3);
    __src = session_id_prefix;
    sVar1 = strlen(session_id_prefix);
    __n = *param_3;
    if (sVar1 <= *param_3) {
      __n = sVar1;
    }
    memcpy(param_2,__src,__n);
    iVar2 = SSL_has_matching_session_id(param_1,param_2,*param_3);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  return 1;
}

