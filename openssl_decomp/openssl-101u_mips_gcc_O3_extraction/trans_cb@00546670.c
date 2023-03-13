
void trans_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = *(int *)(param_3 + 4);
  puVar2 = *(undefined4 **)(iVar1 + 0x20);
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x1c);
  *puVar2 = param_1;
                    /* WARNING: Could not recover jumptable at 0x00546684. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar2[1] = param_2;
  (*UNRECOVERED_JUMPTABLE)(iVar1);
  return;
}

