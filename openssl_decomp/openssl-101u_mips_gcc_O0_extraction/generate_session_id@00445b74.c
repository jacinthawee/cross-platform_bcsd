
undefined4 generate_session_id(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 10;
  while( true ) {
    iVar4 = iVar4 + -1;
    iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(param_2,*param_3);
    uVar1 = session_id_prefix;
    if (iVar2 < 1) {
      return 0;
    }
    uVar3 = (*(code *)PTR_strlen_006a9a24)(session_id_prefix);
    if (*param_3 <= uVar3) {
      uVar3 = *param_3;
    }
    (*(code *)PTR_memcpy_006a9aec)(param_2,uVar1,uVar3);
    iVar2 = (*(code *)PTR_SSL_has_matching_session_id_006a7880)(param_1,param_2,*param_3);
    if (iVar2 == 0) break;
    if (iVar4 == 0) {
      return 0;
    }
  }
  return 1;
}

