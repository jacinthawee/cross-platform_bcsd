
int X509V3_EXT_add_alias(int nid_to,int nid_from)

{
  int **ppiVar1;
  int *data;
  _STACK *st;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *local_5c;
  int local_58 [15];
  
  local_5c = local_58;
  if (-1 < nid_from) {
    local_58[0] = nid_from;
    ppiVar1 = (int **)OBJ_bsearch_(&local_5c,&standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN + 1);
    if (ppiVar1 == (int **)0x0) {
      if ((ext_list == (_STACK *)0x0) || (iVar2 = sk_find(ext_list,local_58), iVar2 == -1))
      goto LAB_000d0e04;
      piVar5 = (int *)sk_value(ext_list,iVar2);
    }
    else {
      piVar5 = *ppiVar1;
    }
    if (piVar5 != (int *)0x0) {
      data = (int *)CRYPTO_malloc(0x38,"v3_lib.c",0x88);
      st = ext_list;
      if (data == (int *)0x0) {
        ERR_put_error(0x22,0x6a,0x41,"v3_lib.c",0x89);
      }
      else {
        iVar2 = piVar5[1];
        iVar3 = piVar5[2];
        iVar4 = piVar5[3];
        *data = *piVar5;
        data[1] = iVar2;
        data[2] = iVar3;
        data[3] = iVar4;
        iVar2 = piVar5[5];
        iVar3 = piVar5[6];
        iVar4 = piVar5[7];
        data[4] = piVar5[4];
        data[5] = iVar2;
        data[6] = iVar3;
        data[7] = iVar4;
        iVar2 = piVar5[9];
        iVar3 = piVar5[10];
        iVar4 = piVar5[0xb];
        data[8] = piVar5[8];
        data[9] = iVar2;
        data[10] = iVar3;
        data[0xb] = iVar4;
        iVar2 = piVar5[0xd];
        data[0xc] = piVar5[0xc];
        data[0xd] = iVar2;
        *data = nid_to;
        data[1] = data[1] | 1;
        if ((st == (_STACK *)0x0) && (st = sk_new(ext_cmp + 1), ext_list = st, st == (_STACK *)0x0))
        {
          ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x4c);
          return 0;
        }
        iVar2 = sk_push(st,data);
        if (iVar2 == 0) {
          ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x50);
          return 0;
        }
        data = (int *)0x1;
      }
      return (int)data;
    }
  }
LAB_000d0e04:
  ERR_put_error(0x22,0x6a,0x66,"v3_lib.c",0x85);
  return 0;
}

