
/* WARNING: Removing unreachable block (ram,0x000a224c) */
/* WARNING: Removing unreachable block (ram,0x000a2254) */
/* WARNING: Removing unreachable block (ram,0x000a17ce) */
/* WARNING: Removing unreachable block (ram,0x000a17d8) */

void _dopr_constprop_0(undefined4 *param_1,int *param_2,int *param_3,undefined4 *param_4,
                      char *param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = __TMC_END__;
  if ((*param_5 != '\0') && (*param_2 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x000a181c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_000a181c::switchdataD_000a1820 +
              (uint)switchD_000a181c::switchdataD_000a1820 * 2))();
    return;
  }
  *param_4 = 0;
  iVar2 = 0;
  if (*param_2 != 0) {
    if ((undefined *)*param_1 == (undefined *)0x0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 1;
      *(undefined *)*param_1 = 0;
    }
  }
  bVar3 = iVar1 == __TMC_END__;
  *param_3 = iVar2 + -1;
  if (bVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

