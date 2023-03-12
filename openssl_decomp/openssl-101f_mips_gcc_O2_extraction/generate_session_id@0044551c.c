
undefined4 generate_session_id(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 10;
  while( true ) {
    iVar4 = iVar4 + -1;
    (*(code *)PTR_RAND_pseudo_bytes_006a8664)(param_2,*param_3);
    uVar1 = session_id_prefix;
    uVar2 = (*(code *)PTR_strlen_006aab30)(session_id_prefix);
    if (*param_3 <= uVar2) {
      uVar2 = *param_3;
    }
    (*(code *)PTR_memcpy_006aabf4)(param_2,uVar1,uVar2);
    iVar3 = (*(code *)PTR_SSL_has_matching_session_id_006a8968)(param_1,param_2,*param_3);
    if (iVar3 == 0) break;
    if (iVar4 == 0) {
      return 0;
    }
  }
  return 1;
}

