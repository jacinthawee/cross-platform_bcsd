
undefined4
ssl_add_serverhello_renegotiate_ext(int param_1,undefined *param_2,int *param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  
  if (param_2 != (undefined *)0x0) {
    iVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4) +
            (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x415);
    if (param_4 <= iVar1) {
      ERR_put_error(0x14,299,0x14f,"t1_reneg.c",0xcc);
      return 0;
    }
    *param_2 = (char)iVar1;
    pvVar2 = memcpy(param_2 + 1,(void *)(*(int *)(param_1 + 0x58) + 0x394),
                    (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4));
    iVar1 = *(int *)(param_1 + 0x58);
    memcpy((void *)((uint)*(byte *)(iVar1 + 0x3d4) + (int)pvVar2),(void *)(iVar1 + 0x3d5),
           (uint)*(byte *)(iVar1 + 0x415));
  }
  *param_3 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x415) +
             (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4) + 1;
  return 1;
}

