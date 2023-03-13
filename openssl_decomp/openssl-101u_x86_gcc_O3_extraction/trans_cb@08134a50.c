
void trans_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_3 + 4);
  puVar2 = *(undefined4 **)(iVar1 + 0x20);
  *puVar2 = param_1;
  puVar2[1] = param_2;
                    /* WARNING: Could not recover jumptable at 0x08134a6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x1c))();
  return;
}

