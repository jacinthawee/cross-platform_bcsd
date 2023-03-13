
int sk_find_ex(_STACK *st,void *data)

{
  undefined *puVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char **local_18;
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = -1;
  local_18 = (char **)data;
  if (st != (_STACK *)0x0) {
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
            if (st->num == iVar2) goto LAB_0052afdc;
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
        data = st->data;
        iVar2 = (*(code *)PTR_OBJ_bsearch_ex__006a8910)(&local_18,data,st->num,4,st->comp,1);
        if (iVar2 != 0) {
          iVar2 = iVar2 - (int)st->data >> 2;
          goto LAB_0052af5c;
        }
      }
LAB_0052afdc:
      iVar2 = -1;
    }
  }
LAB_0052af5c:
  if (local_14 == *(int **)puVar1) {
    return iVar2;
  }
  piVar5 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar7 = *piVar5;
  iVar2 = iVar7 + 1;
  if (iVar2 < piVar5[3]) {
    iVar4 = piVar5[1];
    iVar6 = iVar7;
  }
  else {
    iVar4 = (*(code *)PTR_CRYPTO_realloc_006a7b58)(piVar5[1],piVar5[3] << 3,"stack.c",0x99);
    if (iVar4 == 0) {
      return 0;
    }
    iVar6 = *piVar5;
    piVar5[1] = iVar4;
    piVar5[3] = piVar5[3] << 1;
    if ((iVar7 < iVar6) && (iVar2 = iVar6 + 1, -1 < iVar7)) {
      (*(code *)PTR_memmove_006a9af4)
                (iVar4 + iVar6 * 4 + 8 + (iVar2 - iVar7) * -4,
                 iVar4 + iVar6 * 4 + 4 + (iVar2 - iVar7) * -4);
      *(void **)(piVar5[1] + iVar7 * 4) = data;
      goto LAB_0052b048;
    }
    iVar2 = iVar6 + 1;
  }
  *(void **)(iVar4 + iVar6 * 4) = data;
LAB_0052b048:
  *piVar5 = iVar2;
  piVar5[2] = 0;
  return iVar2;
}

