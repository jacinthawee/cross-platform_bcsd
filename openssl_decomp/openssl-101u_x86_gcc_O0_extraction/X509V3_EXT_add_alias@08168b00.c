
int X509V3_EXT_add_alias(int nid_to,int nid_from)

{
  int **ppiVar1;
  int *data;
  int iVar2;
  int *piVar3;
  int in_GS_OFFSET;
  int line;
  int *local_4c;
  int local_48 [14];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_4c = local_48;
  if (nid_from < 0) {
LAB_08168cb8:
    line = 0x8c;
    iVar2 = 0x66;
  }
  else {
    local_48[0] = nid_from;
    ppiVar1 = (int **)OBJ_bsearch_(&local_4c,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
    if (ppiVar1 == (int **)0x0) {
      if (ext_list != (_STACK *)0x0) {
        iVar2 = sk_find(ext_list,local_48);
        if (iVar2 != -1) {
          piVar3 = (int *)sk_value(ext_list,iVar2);
          goto LAB_08168b52;
        }
      }
      goto LAB_08168cb8;
    }
    piVar3 = *ppiVar1;
LAB_08168b52:
    if (piVar3 == (int *)0x0) goto LAB_08168cb8;
    data = (int *)CRYPTO_malloc(0x38,"v3_lib.c",0x91);
    if (data != (int *)0x0) {
      *data = *piVar3;
      data[1] = piVar3[1];
      data[2] = piVar3[2];
      data[3] = piVar3[3];
      data[4] = piVar3[4];
      data[5] = piVar3[5];
      data[6] = piVar3[6];
      data[7] = piVar3[7];
      data[8] = piVar3[8];
      data[9] = piVar3[9];
      data[10] = piVar3[10];
      data[0xb] = piVar3[0xb];
      data[0xc] = piVar3[0xc];
      iVar2 = piVar3[0xd];
      data[1] = data[1] | 1;
      data[0xd] = iVar2;
      *data = nid_to;
      if (ext_list == (_STACK *)0x0) {
        ext_list = sk_new(ext_cmp);
        if (ext_list == (_STACK *)0x0) {
          ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x4d);
          iVar2 = 0;
          goto LAB_08168bfa;
        }
      }
      iVar2 = sk_push(ext_list,data);
      if (iVar2 == 0) {
        ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x51);
      }
      else {
        iVar2 = 1;
      }
      goto LAB_08168bfa;
    }
    line = 0x92;
    iVar2 = 0x41;
  }
  ERR_put_error(0x22,0x6a,iVar2,"v3_lib.c",line);
  iVar2 = 0;
LAB_08168bfa:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

