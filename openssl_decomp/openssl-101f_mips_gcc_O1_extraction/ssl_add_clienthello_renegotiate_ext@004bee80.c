
undefined4 ssl_add_clienthello_renegotiate_ext(int param_1,byte *param_2,int *param_3,int param_4)

{
  byte bVar1;
  
  if (param_2 != (byte *)0x0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x58) + 0x3d4);
    if (param_4 <= (int)(uint)bVar1) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x12a,0x14f,"t1_reneg.c",0x7b);
      return 0;
    }
    *param_2 = bVar1;
    (*(code *)PTR_memcpy_006aabf4)
              (param_2 + 1,*(int *)(param_1 + 0x58) + 0x394,
               *(undefined *)(*(int *)(param_1 + 0x58) + 0x3d4));
  }
  *param_3 = *(byte *)(*(int *)(param_1 + 0x58) + 0x3d4) + 1;
  return 1;
}

