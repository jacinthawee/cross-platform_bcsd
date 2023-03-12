
void trans_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = *(int *)(param_3 + 4);
  puVar1 = *(undefined4 **)(iVar2 + 0x20);
  UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x1c);
  *puVar1 = param_1;
  puVar1[1] = param_2;
                    /* WARNING: Could not recover jumptable at 0x000af1fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar2);
  return;
}

