
RSA * d2i_Netscape_RSA(RSA **a,uchar **pp,long length,cb *cb)

{
  undefined *puVar1;
  int **ppiVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  long len;
  char *pcVar6;
  cb *pcVar7;
  int **unaff_s0;
  RSA *pRVar8;
  uchar *puStack_70;
  int iStack_6c;
  int **ppiStack_64;
  RSA *pRStack_60;
  undefined *puStack_5c;
  undefined4 uStack_58;
  uchar **ppuStack_54;
  RSA **ppRStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  uchar *local_28;
  int local_24;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  local_28 = *pp;
  local_30 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppiVar2 = (int **)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_28,length,
                                  (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  if (ppiVar2 == (int **)0x0) {
    len = 0x6f;
    pcVar6 = "n_pkey.c";
    local_38 = 0xfb;
    puVar5 = &DAT_000000c8;
    (**(code **)(local_30 + -0x6eac))(0xd);
    pRVar8 = (RSA *)0x0;
  }
  else {
    unaff_s0 = ppiVar2;
    if (**ppiVar2 == 0xb) {
      iVar3 = (**(code **)(local_30 + -0x5470))("private-key",(*ppiVar2)[2],0xb);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(local_30 + -0x7cb4))(*(undefined4 *)*ppiVar2[1]);
        if (iVar3 == 5) {
          pcVar6 = *(char **)(local_30 + -0x7b68);
          if (cb != (cb *)0x0) {
            pcVar6 = (char *)cb;
          }
          len = ppiVar2[1][1] + 8;
          local_38 = 0;
          pRVar8 = (RSA *)d2i_RSA_NET_2_isra_0(a);
          if (pRVar8 != (RSA *)0x0) {
            *pp = local_28;
          }
        }
        else {
          len = 0xa6;
          pcVar6 = "n_pkey.c";
          local_38 = 0x107;
          pRVar8 = (RSA *)0x0;
          (**(code **)(local_30 + -0x6eac))(0xd,200);
        }
        puVar5 = NETSCAPE_ENCRYPTED_PKEY_it;
        ASN1_item_free((ASN1_VALUE *)ppiVar2,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        cb = (cb *)pRVar8;
        goto LAB_005646bc;
      }
    }
    len = 0x92;
    pcVar6 = "n_pkey.c";
    local_38 = 0x102;
    (**(code **)(local_30 + -0x6eac))(0xd,200);
    puVar5 = NETSCAPE_ENCRYPTED_PKEY_it;
    ASN1_item_free((ASN1_VALUE *)ppiVar2,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
    pRVar8 = (RSA *)0x0;
  }
LAB_005646bc:
  if (local_24 == *(int *)puStack_5c) {
    return pRVar8;
  }
  pcStack_4c = d2i_RSA_NET;
  iVar3 = local_24;
  (**(code **)(local_30 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_70 = *(uchar **)puVar5;
  uStack_58 = 0x690000;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppiStack_64 = unaff_s0;
  pRStack_60 = (RSA *)cb;
  ppuStack_54 = pp;
  ppRStack_50 = a;
  ppiVar2 = (int **)ASN1_item_d2i((ASN1_VALUE **)0x0,&puStack_70,len,
                                  (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  if (ppiVar2 == (int **)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,200,0x6f,"n_pkey.c",0xfb);
    pRVar8 = (RSA *)0x0;
  }
  else {
    if (**ppiVar2 == 0xb) {
      iVar4 = (*(code *)PTR_strncmp_006a9970)("private-key",(*ppiVar2)[2],0xb);
      if (iVar4 == 0) {
        iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)*ppiVar2[1]);
        if (iVar4 == 5) {
          pcVar7 = (cb *)PTR_EVP_read_pw_string_006a7278;
          if ((cb *)pcVar6 != (cb *)0x0) {
            pcVar7 = (cb *)pcVar6;
          }
          pRVar8 = (RSA *)d2i_RSA_NET_2_isra_0
                                    (iVar3,ppiVar2[1][1],ppiVar2[1][1] + 8,pcVar7,local_38);
          if (pRVar8 != (RSA *)0x0) {
            *(uchar **)puVar5 = puStack_70;
          }
        }
        else {
          pRVar8 = (RSA *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,200,0xa6,"n_pkey.c",0x107);
        }
        ASN1_item_free((ASN1_VALUE *)ppiVar2,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        goto LAB_005648ac;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,200,0x92,"n_pkey.c",0x102);
    ASN1_item_free((ASN1_VALUE *)ppiVar2,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
    pRVar8 = (RSA *)0x0;
  }
LAB_005648ac:
  if (iStack_6c == *(int *)puVar1) {
    return pRVar8;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return (RSA *)0x0;
}

