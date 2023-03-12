
undefined4
ssl_add_serverhello_renegotiate_ext(int param_1,undefined *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != (undefined *)0x0) {
    iVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4) +
            (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x415);
    if (param_4 <= iVar1) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,299,0x14f,"t1_reneg.c",0xcc);
      return 0;
    }
    *param_2 = (char)iVar1;
    iVar1 = (*(code *)PTR_memcpy_006aabf4)
                      (param_2 + 1,*(int *)(param_1 + 0x58) + 0x394,
                       *(undefined *)(*(int *)(param_1 + 0x58) + 0x3d4));
    iVar2 = *(int *)(param_1 + 0x58);
    (*(code *)PTR_memcpy_006aabf4)
              (iVar1 + (uint)*(byte *)(iVar2 + 0x3d4),iVar2 + 0x3d5,*(undefined *)(iVar2 + 0x415));
  }
  *param_3 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4) +
             (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x415) + 1;
  return 1;
}

