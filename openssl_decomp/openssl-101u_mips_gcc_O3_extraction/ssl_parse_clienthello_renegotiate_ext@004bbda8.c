
undefined4
ssl_parse_clienthello_renegotiate_ext(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 < 1) {
    uVar3 = 0x9a;
  }
  else {
    uVar1 = (uint)*param_2;
    if (param_3 == uVar1 + 1) {
      iVar4 = *(int *)(param_1 + 0x58);
      if (uVar1 == *(byte *)(iVar4 + 0x3d4)) {
        iVar2 = (*(code *)PTR_memcmp_006a9ad0)(param_2 + 1,iVar4 + 0x394,uVar1);
        if (iVar2 == 0) {
          *(undefined4 *)(iVar4 + 0x418) = 1;
          return 1;
        }
        uVar3 = 0xb4;
      }
      else {
        uVar3 = 0xac;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,300,0x151,"t1_reneg.c",uVar3);
      *param_4 = 0x28;
      return 0;
    }
    uVar3 = 0xa4;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,300,0x150,"t1_reneg.c",uVar3);
  *param_4 = 0x2f;
  return 0;
}

