
int sk_find(_STACK *st,void *data)

{
  undefined *puVar1;
  int iVar2;
  char **ppcVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  _STACK *unaff_s0;
  int iVar8;
  char **ppcStack_50;
  int *piStack_4c;
  _STACK *p_Stack_44;
  undefined *puStack_40;
  code *pcStack_3c;
  _func_257 *local_28;
  undefined4 local_24;
  undefined *local_20;
  char **local_18;
  int *local_14;
  
  puStack_40 = PTR___stack_chk_guard_006a9ae8;
  local_20 = &_gp;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = -1;
  p_Stack_44 = unaff_s0;
  local_18 = (char **)data;
  if (st != (_STACK *)0x0) {
    p_Stack_44 = st;
    if (st->comp == (_func_257 *)0x0) {
      iVar2 = -1;
      if (0 < st->num) {
        ppcVar3 = st->data;
        if ((char *)data == *ppcVar3) {
          iVar2 = 0;
        }
        else {
          iVar2 = 0;
          do {
            ppcVar3 = ppcVar3 + 1;
            iVar2 = iVar2 + 1;
            if (st->num == iVar2) goto LAB_0052aeb4;
          } while ((char *)data != *ppcVar3);
        }
      }
    }
    else {
      if (st->sorted == 0) {
        (*(code *)PTR_qsort_006a9988)(st->data,st->num,4);
        st->sorted = 1;
      }
      data = local_18;
      if (local_18 != (char **)0x0) {
        local_28 = st->comp;
        data = st->data;
        local_24 = 2;
        iVar2 = (**(code **)(local_20 + -0x64d0))(&local_18,data,st->num,4);
        if (iVar2 != 0) {
          iVar2 = iVar2 - (int)st->data >> 2;
          goto LAB_0052ae34;
        }
      }
LAB_0052aeb4:
      iVar2 = -1;
    }
  }
LAB_0052ae34:
  if (local_14 == *(int **)puStack_40) {
    return iVar2;
  }
  pcStack_3c = sk_find_ex;
  piVar6 = local_14;
  (**(code **)(local_20 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piStack_4c = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = -1;
  ppcStack_50 = (char **)data;
  if (piVar6 != (int *)0x0) {
    if (piVar6[4] == 0) {
      iVar2 = -1;
      if (0 < *piVar6) {
        piVar4 = (int *)piVar6[1];
        if ((char **)data == (char **)*piVar4) {
          iVar2 = 0;
        }
        else {
          iVar2 = 0;
          do {
            piVar4 = piVar4 + 1;
            iVar2 = iVar2 + 1;
            if (*piVar6 == iVar2) goto LAB_0052afdc;
          } while ((char **)data != (char **)*piVar4);
        }
      }
    }
    else {
      if (piVar6[2] == 0) {
        (*(code *)PTR_qsort_006a9988)(piVar6[1],*piVar6,4);
        piVar6[2] = 1;
      }
      data = ppcStack_50;
      if (ppcStack_50 != (char **)0x0) {
        data = (void *)piVar6[1];
        iVar2 = (*(code *)PTR_OBJ_bsearch_ex__006a8910)(&ppcStack_50,data,*piVar6,4,piVar6[4],1);
        if (iVar2 != 0) {
          iVar2 = iVar2 - piVar6[1] >> 2;
          goto LAB_0052af5c;
        }
      }
LAB_0052afdc:
      iVar2 = -1;
    }
  }
LAB_0052af5c:
  if (piStack_4c == *(int **)puVar1) {
    return iVar2;
  }
  piVar6 = piStack_4c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar8 = *piVar6;
  iVar2 = iVar8 + 1;
  if (iVar2 < piVar6[3]) {
    iVar5 = piVar6[1];
    iVar7 = iVar8;
  }
  else {
    iVar5 = (*(code *)PTR_CRYPTO_realloc_006a7b58)(piVar6[1],piVar6[3] << 3,"stack.c",0x99);
    if (iVar5 == 0) {
      return 0;
    }
    iVar7 = *piVar6;
    piVar6[1] = iVar5;
    piVar6[3] = piVar6[3] << 1;
    if ((iVar8 < iVar7) && (iVar2 = iVar7 + 1, -1 < iVar8)) {
      (*(code *)PTR_memmove_006a9af4)
                (iVar5 + iVar7 * 4 + 8 + (iVar2 - iVar8) * -4,
                 iVar5 + iVar7 * 4 + 4 + (iVar2 - iVar8) * -4);
      *(void **)(piVar6[1] + iVar8 * 4) = data;
      goto LAB_0052b048;
    }
    iVar2 = iVar7 + 1;
  }
  *(void **)(iVar5 + iVar7 * 4) = data;
LAB_0052b048:
  *piVar6 = iVar2;
  piVar6[2] = 0;
  return iVar2;
}

