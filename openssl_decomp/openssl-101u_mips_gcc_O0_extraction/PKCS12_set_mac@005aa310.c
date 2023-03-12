
int PKCS12_set_mac(PKCS12 *p12,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  EVP_MD *md_type)

{
  undefined *puVar1;
  undefined *puVar2;
  PKCS12_MAC_DATA *pPVar3;
  ASN1_INTEGER *pAVar4;
  int iVar5;
  uchar *puVar6;
  undefined4 uVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_TYPE *pAVar9;
  int iVar10;
  char **ppcVar11;
  int **ppiVar12;
  char *pcVar13;
  X509_ALGOR *pXVar14;
  char *pcVar15;
  undefined4 *puVar16;
  int iVar17;
  ASN1_OCTET_STRING *pAVar18;
  int *piVar19;
  int local_70;
  char acStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (md_type == (EVP_MD *)0x0) {
    md_type = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
  }
  pPVar3 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar3;
  if (pPVar3 == (PKCS12_MAC_DATA *)0x0) {
    local_70 = 0x6e;
    piVar19 = (int *)&DAT_00000090;
  }
  else if (iter < 2) {
LAB_005aa3d4:
    pAVar18 = pPVar3->salt;
    if (saltlen == 0) {
      saltlen = 8;
    }
    puVar6 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(saltlen,"p12_mutl.c",0xb0);
    pAVar18->data = puVar6;
    if (puVar6 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",0xb1);
    }
    else {
      pAVar18 = p12->mac->salt;
      pAVar18->length = saltlen;
      if (salt == (uchar *)0x0) {
        iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(pAVar18->data,saltlen);
        if (iVar5 < 1) goto LAB_005aa5d4;
      }
      else {
        (*(code *)PTR_memcpy_006a9aec)(pAVar18->data,salt,saltlen);
      }
      pXVar14 = p12->mac->dinfo->algor;
      uVar7 = (*(code *)PTR_EVP_MD_type_006a73cc)(md_type);
      pAVar8 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(uVar7);
      pPVar3 = p12->mac;
      pXVar14->algorithm = pAVar8;
      pXVar14 = pPVar3->dinfo->algor;
      pAVar9 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
      pXVar14->parameter = pAVar9;
      puVar1 = PTR_OBJ_obj2nid_006a712c;
      if (pAVar9 != (ASN1_TYPE *)0x0) {
        pAVar8 = p12->authsafes->type;
        p12->mac->dinfo->algor->parameter->type = 5;
        iVar5 = (*(code *)puVar1)(pAVar8);
        if (iVar5 == 0x15) {
          piVar19 = &local_70;
          pcVar13 = acStack_6c;
          pcVar15 = pcVar13;
          iVar5 = PKCS12_gen_mac_part_0(p12,pass,passlen);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(p12->mac->dinfo->digest);
            if (iVar5 == 0) {
              pcVar15 = "p12_mutl.c";
              local_70 = 0x6f;
              pcVar13 = (char *)0x7b;
              piVar19 = (int *)&DAT_00000098;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x23);
            }
            else {
              iVar5 = 1;
            }
            goto LAB_005aa500;
          }
        }
        else {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6b,0x79,"p12_mutl.c",0x4f);
        }
        local_70 = 0x6d;
        piVar19 = (int *)&DAT_00000094;
        goto LAB_005aa574;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",0xbc);
    }
LAB_005aa5d4:
    local_70 = 0x6e;
    piVar19 = (int *)&DAT_00000090;
  }
  else {
    pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(2);
    pPVar3->iter = pAVar4;
    if (pAVar4 == (ASN1_INTEGER *)0x0) {
      uVar7 = 0xa6;
    }
    else {
      iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(p12->mac->iter,iter);
      if (iVar5 != 0) {
        pPVar3 = p12->mac;
        goto LAB_005aa3d4;
      }
      uVar7 = 0xaa;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",uVar7);
    local_70 = 0x6e;
    piVar19 = (int *)&DAT_00000090;
  }
LAB_005aa574:
  pcVar15 = "p12_mutl.c";
  pcVar13 = (char *)0x7b;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23);
  iVar5 = 0;
LAB_005aa500:
  if (local_2c == *(int *)puVar2) {
    return iVar5;
  }
  iVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pPVar3 = PKCS12_MAC_DATA_new();
  *(PKCS12_MAC_DATA **)(iVar5 + 4) = pPVar3;
  if (pPVar3 != (PKCS12_MAC_DATA *)0x0) {
    if (1 < (int)pcVar13) {
      pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(2);
      pPVar3->iter = pAVar4;
      if (pAVar4 == (ASN1_INTEGER *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",0xa6);
        return 0;
      }
      iVar10 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)
                         (*(undefined4 *)(*(int *)(iVar5 + 4) + 8),pcVar13);
      if (iVar10 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",0xaa);
        return 0;
      }
      pPVar3 = *(PKCS12_MAC_DATA **)(iVar5 + 4);
    }
    pAVar18 = pPVar3->salt;
    if (pcVar15 == (char *)0x0) {
      pcVar15 = &DAT_00000008;
    }
    puVar6 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pcVar15,"p12_mutl.c",0xb0);
    pAVar18->data = puVar6;
    if (puVar6 == (uchar *)0x0) {
      uVar7 = 0xb1;
    }
    else {
      ppcVar11 = *(char ***)(*(int *)(iVar5 + 4) + 4);
      *ppcVar11 = pcVar15;
      if (local_70 == 0) {
        iVar10 = (*(code *)PTR_RAND_bytes_006a7574)(ppcVar11[2],pcVar15);
        if (iVar10 < 1) {
          return 0;
        }
      }
      else {
        (*(code *)PTR_memcpy_006a9aec)(ppcVar11[2],local_70,pcVar15);
      }
      puVar16 = *(undefined4 **)**(undefined4 **)(iVar5 + 4);
      uVar7 = (*(code *)PTR_EVP_MD_type_006a73cc)(piVar19);
      uVar7 = (*(code *)PTR_OBJ_nid2obj_006a7140)(uVar7);
      ppiVar12 = *(int ***)(iVar5 + 4);
      *puVar16 = uVar7;
      iVar17 = **ppiVar12;
      iVar10 = (*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
      *(int *)(iVar17 + 4) = iVar10;
      if (iVar10 != 0) {
        **(undefined4 **)(***(int ***)(iVar5 + 4) + 4) = 5;
        return 1;
      }
      uVar7 = 0xbc;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",uVar7);
  }
  return 0;
}

