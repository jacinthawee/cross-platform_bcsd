
/* WARNING: Removing unreachable block (ram,0x005280c8) */

void _dopr_constprop_0(int *param_1,uint *param_2,uint *param_3,uint *param_4,char *param_5)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar6 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar7 = 0;
  iVar5 = (int)*param_5;
  uVar8 = *param_2;
  do {
    bVar1 = uVar7 < uVar8;
    if (iVar5 != 0) goto LAB_005272f4;
    while( true ) {
      uVar8 = (uint)(uVar8 - 1 < uVar7);
      *param_4 = uVar8;
      if (uVar8 != 0) {
        uVar7 = *param_2 - 1;
      }
      uVar4 = uVar7;
      if (*param_2 <= uVar7) goto LAB_00527238;
      if (*param_1 != 0) break;
      trap(0);
LAB_005272f4:
      if (bVar1) {
                    /* WARNING: Could not recover jumptable at 0x00527318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)switchD_00527318::switchdataD_00667f40)();
        return;
      }
    }
    uVar4 = uVar7 + 1;
    *(undefined *)(*param_1 + uVar7) = 0;
LAB_00527238:
    uVar7 = uVar4 - 1;
    iVar3 = *(int *)puVar2;
    *param_3 = uVar7;
    if (iVar6 == iVar3) {
      return;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
  } while( true );
}

