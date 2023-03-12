
void CMS_ReceiptRequest_get0_values
               (undefined4 *param_1,undefined4 *param_2,int *param_3,int *param_4,
               undefined4 *param_5)

{
  int *piVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  piVar1 = (int *)param_1[1];
  if (*piVar1 == 0) {
    if (param_3 != (int *)0x0) {
      *param_3 = piVar1[1];
    }
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    if (param_3 != (int *)0x0) {
      *param_3 = -1;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = piVar1[1];
    }
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = param_1[2];
  }
  return;
}

