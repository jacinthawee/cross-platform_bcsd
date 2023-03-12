
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
  int **ppiVar11;
  char *pcVar12;
  X509_ALGOR *pXVar13;
  char *pcVar14;
  undefined4 *puVar15;
  int iVar16;
  ASN1_OCTET_STRING *pAVar17;
  int *piVar18;
  int local_70;
  char acStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (md_type == (EVP_MD *)0x0) {
    md_type = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
  }
  pPVar3 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar3;
  if (pPVar3 == (PKCS12_MAC_DATA *)0x0) {
    local_70 = 0x6e;
    piVar18 = (int *)0x8d;
  }
  else if (iter < 2) {
LAB_005aceb4:
    puVar1 = PTR_CRYPTO_malloc_006a8108;
    pAVar17 = pPVar3->salt;
    if (saltlen == 0) {
      saltlen = 8;
    }
    pAVar17->length = saltlen;
    puVar6 = (uchar *)(*(code *)puVar1)(saltlen,"p12_mutl.c",0xac);
    pAVar17->data = puVar6;
    if (puVar6 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",0xad);
    }
    else {
      if (salt == (uchar *)0x0) {
        iVar5 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(p12->mac->salt->data,saltlen);
        if (iVar5 < 0) goto LAB_005ad0b8;
      }
      else {
        (*(code *)PTR_memcpy_006aabf4)(p12->mac->salt->data,salt,saltlen);
      }
      pXVar13 = p12->mac->dinfo->algor;
      uVar7 = (*(code *)PTR_EVP_MD_type_006a84cc)(md_type);
      pAVar8 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(uVar7);
      pPVar3 = p12->mac;
      pXVar13->algorithm = pAVar8;
      pXVar13 = pPVar3->dinfo->algor;
      pAVar9 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
      pXVar13->parameter = pAVar9;
      puVar1 = PTR_OBJ_obj2nid_006a822c;
      if (pAVar9 != (ASN1_TYPE *)0x0) {
        pAVar8 = p12->authsafes->type;
        p12->mac->dinfo->algor->parameter->type = 5;
        iVar5 = (*(code *)puVar1)(pAVar8);
        if (iVar5 == 0x15) {
          piVar18 = &local_70;
          pcVar12 = acStack_6c;
          pcVar14 = pcVar12;
          iVar5 = PKCS12_gen_mac_part_0(p12,pass,passlen);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(p12->mac->dinfo->digest);
            if (iVar5 == 0) {
              pcVar14 = "p12_mutl.c";
              local_70 = 0x6f;
              pcVar12 = (char *)0x7b;
              piVar18 = (int *)&DAT_00000095;
              (*(code *)PTR_ERR_put_error_006a9030)(0x23);
            }
            else {
              iVar5 = 1;
            }
            goto LAB_005acfe0;
          }
        }
        else {
          (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6b,0x79,"p12_mutl.c",0x4e);
        }
        local_70 = 0x6d;
        piVar18 = (int *)0x91;
        goto LAB_005ad054;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",0xb7);
    }
LAB_005ad0b8:
    local_70 = 0x6e;
    piVar18 = (int *)0x8d;
  }
  else {
    pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(2);
    pPVar3->iter = pAVar4;
    if (pAVar4 == (ASN1_INTEGER *)0x0) {
      uVar7 = 0xa2;
    }
    else {
      iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(p12->mac->iter,iter);
      if (iVar5 != 0) {
        pPVar3 = p12->mac;
        goto LAB_005aceb4;
      }
      uVar7 = 0xa6;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",uVar7);
    local_70 = 0x6e;
    piVar18 = (int *)0x8d;
  }
LAB_005ad054:
  pcVar14 = "p12_mutl.c";
  pcVar12 = (char *)0x7b;
  (*(code *)PTR_ERR_put_error_006a9030)(0x23);
  iVar5 = 0;
LAB_005acfe0:
  if (local_2c == *(int *)puVar2) {
    return iVar5;
  }
  iVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pPVar3 = PKCS12_MAC_DATA_new();
  *(PKCS12_MAC_DATA **)(iVar5 + 4) = pPVar3;
  if (pPVar3 != (PKCS12_MAC_DATA *)0x0) {
    if (1 < (int)pcVar12) {
      pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(2);
      pPVar3->iter = pAVar4;
      if (pAVar4 == (ASN1_INTEGER *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",0xa2);
        return 0;
      }
      iVar10 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)
                         (*(undefined4 *)(*(int *)(iVar5 + 4) + 8),pcVar12);
      if (iVar10 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",0xa6);
        return 0;
      }
      pPVar3 = *(PKCS12_MAC_DATA **)(iVar5 + 4);
    }
    puVar2 = PTR_CRYPTO_malloc_006a8108;
    pAVar17 = pPVar3->salt;
    if (pcVar14 == (char *)0x0) {
      pcVar14 = &DAT_00000008;
    }
    pAVar17->length = (int)pcVar14;
    puVar6 = (uchar *)(*(code *)puVar2)(pcVar14,"p12_mutl.c",0xac);
    pAVar17->data = puVar6;
    if (puVar6 == (uchar *)0x0) {
      uVar7 = 0xad;
    }
    else {
      if (local_70 == 0) {
        iVar10 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)
                           (*(undefined4 *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 8),pcVar14);
        if (iVar10 < 0) {
          return 0;
        }
      }
      else {
        (*(code *)PTR_memcpy_006aabf4)
                  (*(undefined4 *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 8),local_70,pcVar14);
      }
      puVar15 = *(undefined4 **)**(undefined4 **)(iVar5 + 4);
      uVar7 = (*(code *)PTR_EVP_MD_type_006a84cc)(piVar18);
      uVar7 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar7);
      ppiVar11 = *(int ***)(iVar5 + 4);
      *puVar15 = uVar7;
      iVar16 = **ppiVar11;
      iVar10 = (*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
      *(int *)(iVar16 + 4) = iVar10;
      if (iVar10 != 0) {
        **(undefined4 **)(***(int ***)(iVar5 + 4) + 4) = 5;
        return 1;
      }
      uVar7 = 0xb7;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",uVar7);
  }
  return 0;
}

