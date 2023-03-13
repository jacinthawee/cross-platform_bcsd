
undefined4 def_generate_session_id(SSL *param_1,uchar *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 10;
  while( true ) {
    iVar2 = iVar2 + -1;
    iVar1 = (*(code *)PTR_RAND_bytes_006a7574)(param_2,*param_3);
    if (iVar1 < 1) {
      return 0;
    }
    iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3);
    if (iVar1 == 0) break;
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 1;
}

