
/* WARNING: Removing unreachable block (ram,0x005a9d80) */
/* WARNING: Removing unreachable block (ram,0x005a9d38) */
/* WARNING: Removing unreachable block (ram,0x005a9d88) */
/* WARNING: Removing unreachable block (ram,0x005a9d9c) */
/* WARNING: Removing unreachable block (ram,0x005a9d40) */
/* WARNING: Removing unreachable block (ram,0x005a9d58) */
/* WARNING: Removing unreachable block (ram,0x005a9d64) */
/* WARNING: Removing unreachable block (ram,0x005a9de0) */
/* WARNING: Removing unreachable block (ram,0x005a9e08) */
/* WARNING: Removing unreachable block (ram,0x005a9d70) */
/* WARNING: Removing unreachable block (ram,0x005a9d74) */
/* WARNING: Removing unreachable block (ram,0x005a9e18) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PKCS12_key_gen_uni(uchar *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  undefined *puVar1;
  int *piVar2;
  uchar *puVar3;
  int iVar4;
  uchar *puVar5;
  PKCS12_SAFEBAG *bag;
  ASN1_TYPE *pAVar6;
  X509 *pXVar7;
  PKCS8_PRIV_KEY_INFO *pPVar8;
  stack_st_PKCS7 *psVar9;
  PKCS7 *p7;
  stack_st_PKCS12_SAFEBAG *psVar10;
  undefined4 uVar11;
  uchar *puVar12;
  undefined *puVar13;
  PKCS12 *p12;
  X509 *pass_00;
  X509 *pass_01;
  int *piVar14;
  int *piVar15;
  undefined4 uVar16;
  char *pcVar17;
  int *piVar18;
  int iVar19;
  int unaff_s2;
  int *unaff_s4;
  uchar *unaff_s5;
  ASN1_STRING *pAVar20;
  char *pcVar21;
  int unaff_s7;
  int iVar22;
  X509 *pXStack_120;
  PKCS12 *pPStack_11c;
  int *piStack_118;
  undefined *puStack_114;
  uchar *puStack_110;
  int *piStack_10c;
  EVP_MD *pEStack_108;
  uchar *puStack_104;
  EVP_MD *pEStack_100;
  int iStack_fc;
  uint uStack_f8;
  undefined4 uStack_f4;
  uchar *puStack_bc;
  X509 *pXStack_b8;
  int iStack_b4;
  undefined *puStack_b0;
  int iStack_ac;
  int iStack_a8;
  uchar *puStack_a4;
  int *piStack_a0;
  code *pcStack_9c;
  int local_88;
  int iStack_84;
  undefined *local_80;
  uchar *puStack_7c;
  EVP_MD *pEStack_78;
  uchar *local_74;
  uchar *local_70;
  undefined *local_6c;
  int local_68;
  int local_64;
  uchar **local_60;
  char *local_5c;
  int local_58;
  uchar *local_54;
  int local_50;
  int local_4c;
  undefined auStack_44 [24];
  uchar *local_2c;
  
  puStack_b0 = auStack_44;
  local_60 = (uchar **)PTR___stack_chk_guard_006a9ae8;
  local_54 = out;
  local_80 = &_gp;
  local_2c = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  iVar4 = passlen;
  piStack_10c = (int *)saltlen;
  local_74 = pass;
  local_70 = salt;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_b0);
  iStack_ac = (**(code **)(local_80 + -0x6920))(md_type);
  piVar2 = (int *)(**(code **)(local_80 + -0x6fa4))(md_type);
  if ((int)piVar2 < 0) {
    iVar22 = 0;
  }
  else {
    local_5c = "encrypt";
    local_68 = (**(code **)(local_80 + -0x7dd8))(iStack_ac,s_p12_key_c_0066fd64,0x8d);
    unaff_s2 = (**(code **)(local_80 + -0x7dd8))(piVar2,s_p12_key_c_0066fd64,0x8e);
    local_6c = (undefined *)
               (**(code **)(local_80 + -0x7dd8))(iStack_ac + 1,s_p12_key_c_0066fd64,0x8f);
    if (iStack_ac == 0) {
      trap(7);
    }
    local_4c = ((iStack_ac + saltlen + -1) / iStack_ac) * iStack_ac;
    if (passlen == 0) {
      local_50 = 0;
    }
    else {
      if (iStack_ac == 0) {
        trap(7);
      }
      local_50 = ((iStack_ac + passlen + -1) / iStack_ac) * iStack_ac;
    }
    local_58 = local_50 + local_4c;
    unaff_s5 = (uchar *)(**(code **)(local_80 + -0x7dd8))(local_58,local_5c + -0x29c,0x96);
    unaff_s7 = (**(code **)(local_80 + -0x7c2c))();
    local_64 = (**(code **)(local_80 + -0x7c2c))();
    if (((((local_68 != 0) && (unaff_s2 != 0)) && (local_6c != (undefined *)0x0)) &&
        ((unaff_s5 != (uchar *)0x0 && (unaff_s7 != 0)))) && (local_64 != 0)) {
      if (0 < iStack_ac) {
        (**(code **)(local_80 + -0x53ec))(local_68,id & 0xff,iStack_ac);
      }
      puVar12 = unaff_s5;
      if (0 < local_4c) {
        puVar5 = unaff_s5;
        do {
          puVar3 = puVar5 + 1;
          if (saltlen == 0) {
            trap(7);
          }
          *puVar5 = local_70[((int)puVar5 - (int)unaff_s5) % saltlen];
          puVar5 = puVar3;
          puVar12 = unaff_s5 + local_4c;
        } while (unaff_s5 + local_4c != puVar3);
      }
      if (0 < local_50) {
        puVar5 = puVar12;
        do {
          puVar3 = puVar5 + 1;
          if (passlen == 0) {
            trap(7);
          }
          *puVar5 = local_74[((int)puVar5 - (int)puVar12) % passlen];
          puVar5 = puVar3;
        } while (puVar12 + local_50 != puVar3);
      }
      saltlen = (int)(iter < 2);
      local_74 = (uchar *)(iStack_ac - (int)unaff_s5);
      local_70 = local_6c + 1;
      while (((iVar4 = (**(code **)(local_80 + -0x7864))(puStack_b0,md_type,0), iVar4 != 0 &&
              (iVar4 = (**(code **)(local_80 + -0x7860))(puStack_b0,local_68,iStack_ac), iVar4 != 0)
              ) && ((iVar4 = (**(code **)(local_80 + -0x7860))(puStack_b0,unaff_s5,local_58),
                    iVar4 != 0 &&
                    (iVar4 = (**(code **)(local_80 + -0x785c))(puStack_b0,unaff_s2,0), iVar4 != 0)))
             )) {
        passlen = 1;
        if (saltlen == 0) {
          do {
            iVar4 = (**(code **)(local_80 + -0x7864))(puStack_b0,md_type,0);
            if (((iVar4 == 0) ||
                (iVar4 = (**(code **)(local_80 + -0x7860))(puStack_b0,unaff_s2,piVar2), iVar4 == 0))
               || (iVar4 = (**(code **)(local_80 + -0x785c))(puStack_b0,unaff_s2,0), iVar4 == 0))
            goto LAB_005a8fe4;
            passlen = passlen + 1;
          } while (iter != passlen);
        }
        passlen = (int)((int)piVar2 < n);
        salt = (uchar *)n;
        if ((uchar *)passlen != (uchar *)0x0) {
          salt = (uchar *)piVar2;
        }
        iVar4 = unaff_s2;
        (**(code **)(local_80 + -0x52f4))(local_54);
        if ((uchar *)passlen == (uchar *)0x0) {
          iVar22 = 1;
          goto LAB_005a900c;
        }
        if (0 < iStack_ac) {
          iVar4 = 0;
          puVar13 = local_6c;
          do {
            if (piVar2 == (int *)0x0) {
              trap(7);
            }
            iVar22 = iVar4 % (int)piVar2;
            iVar4 = iVar4 + 1;
            *puVar13 = *(undefined *)(unaff_s2 + iVar22);
            puVar13 = puVar13 + 1;
          } while (iStack_ac != iVar4);
        }
        iVar4 = (**(code **)(local_80 + -0x74dc))(local_6c,iStack_ac,local_64);
        if ((iVar4 == 0) || (iVar4 = (**(code **)(local_80 + -0x7d24))(local_64,1), iVar4 == 0))
        break;
        passlen = (int)unaff_s5;
        if (0 < local_58) {
          do {
            iVar4 = (**(code **)(local_80 + -0x74dc))(passlen,iStack_ac,unaff_s7);
            if (((iVar4 == 0) ||
                (iVar4 = (**(code **)(local_80 + -0x683c))(unaff_s7,unaff_s7,local_64), iVar4 == 0))
               || (iVar4 = (**(code **)(local_80 + -0x7be0))(unaff_s7,local_6c), iVar4 == 0))
            goto LAB_005a8fe4;
            iVar22 = (**(code **)(local_80 + -0x7bec))(unaff_s7);
            iVar4 = iVar22 + 7;
            if (iVar22 + 7 < 0) {
              iVar4 = iVar22 + 0xe;
            }
            iVar4 = iVar4 >> 3;
            if (iStack_ac < iVar4) {
              iVar4 = (**(code **)(local_80 + -0x7be0))(unaff_s7,local_6c);
              if (iVar4 == 0) goto LAB_005a8fe4;
              (**(code **)(local_80 + -0x52f4))(passlen,local_70,iStack_ac);
            }
            else {
              if (iVar4 < iStack_ac) {
                local_50 = iVar4;
                (**(code **)(local_80 + -0x53ec))(passlen,0,iStack_ac - iVar4);
                iVar4 = (**(code **)(local_80 + -0x7be0))
                                  (unaff_s7,unaff_s5 + ((int)(local_74 + passlen) - local_50));
              }
              else {
                iVar4 = (**(code **)(local_80 + -0x7be0))(unaff_s7,passlen);
              }
              if (iVar4 == 0) goto LAB_005a8fe4;
            }
            passlen = passlen + iStack_ac;
          } while (passlen - (int)unaff_s5 < local_58);
        }
        n = n - (int)piVar2;
        local_54 = local_54 + (int)piVar2;
      }
    }
LAB_005a8fe4:
    salt = &DAT_00000041;
    iVar4 = 0x6f;
    piStack_10c = (int *)(local_5c + -0x29c);
    iVar22 = 0;
    local_88 = 0xda;
    (**(code **)(local_80 + -0x6eac))(0x23);
LAB_005a900c:
    (**(code **)(local_80 + -0x7f58))(unaff_s2);
    (**(code **)(local_80 + -0x7f58))(local_6c);
    (**(code **)(local_80 + -0x7f58))(local_68);
    (**(code **)(local_80 + -0x7f58))(unaff_s5);
    (**(code **)(local_80 + -0x7dc4))(unaff_s7);
    (**(code **)(local_80 + -0x7dc4))(local_64);
    (**(code **)(local_80 + -0x7fac))(puStack_b0);
    iStack_ac = iVar22;
    unaff_s4 = piVar2;
  }
  if (local_2c == *local_60) {
    return iVar22;
  }
  pcStack_9c = PKCS12_key_gen_asc;
  puVar12 = local_2c;
  (**(code **)(local_80 + -0x5330))();
  puStack_114 = PTR___stack_chk_guard_006a9ae8;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_a8 = unaff_s2;
  puStack_a4 = (uchar *)passlen;
  piStack_a0 = unaff_s4;
  if (puVar12 == (uchar *)0x0) {
    puStack_bc = (uchar *)0x0;
    pXStack_b8 = (X509 *)0x0;
LAB_005a9350:
    pass_00 = pXStack_b8;
    pcVar17 = (char *)piStack_10c;
    piStack_118 = (int *)PKCS12_key_gen_uni(puVar12,(int)pXStack_b8,salt,(int)piStack_10c,local_88,
                                            iStack_84,(int)local_80,puStack_7c,pEStack_78);
    piVar2 = (int *)salt;
    if ((int)piStack_118 < 1) {
      piVar14 = (int *)0x0;
    }
    else {
      piVar14 = piStack_118;
      if (puStack_bc != (uchar *)0x0) {
        pass_00 = pXStack_b8;
        (*(code *)PTR_OPENSSL_cleanse_006a7074)();
        (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_bc);
        piVar2 = (int *)salt;
      }
    }
  }
  else {
    puVar5 = OPENSSL_asc2uni((char *)puVar12,iVar4,&puStack_bc,(int *)&pXStack_b8);
    puVar12 = puStack_bc;
    if (puVar5 != (uchar *)0x0) goto LAB_005a9350;
    piVar2 = (int *)&DAT_00000041;
    pcVar17 = s_p12_key_c_0066fd64;
    pass_00 = (X509 *)&DAT_0000006e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23);
    piVar14 = (int *)0x0;
    piStack_118 = (int *)salt;
  }
  if (iStack_b4 == *(int *)puStack_114) {
    return (int)piVar14;
  }
  uStack_f4 = 0x5a9434;
  iVar4 = iStack_b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  puStack_110 = puStack_7c;
  pEStack_108 = pEStack_78;
  iVar19 = 0;
  pEStack_100 = md_type;
  pPStack_11c = *(PKCS12 **)PTR___stack_chk_guard_006a9ae8;
  pass_01 = pass_00;
  piVar14 = piVar2;
  piVar18 = (int *)pcVar17;
  puStack_104 = unaff_s5;
  iStack_fc = unaff_s7;
  uStack_f8 = saltlen;
  iVar22 = (*(code *)PTR_sk_num_006a6e2c)(iVar4);
  if (0 < iVar22) {
    do {
      bag = (PKCS12_SAFEBAG *)(*(code *)PTR_sk_value_006a6e24)(iVar4,iVar19);
      pAVar6 = PKCS12_get_attr_gen(bag->attrib,0x9c);
      if (pAVar6 == (ASN1_TYPE *)0x0) {
        pcVar21 = (char *)0x0;
      }
      else {
        pcVar21 = (pAVar6->value).ptr;
      }
      pass_01 = (X509 *)0x9d;
      pAVar6 = PKCS12_get_attr_gen(bag->attrib,0x9d);
      if (pAVar6 == (ASN1_TYPE *)0x0) {
        pAVar20 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar20 = (pAVar6->value).asn1_string;
      }
      iVar22 = (*(code *)PTR_OBJ_obj2nid_006a712c)(bag->type);
      if (iVar22 == 0x97) {
        if ((piVar2 != (int *)0x0) && (*piVar2 == 0)) {
          piVar14 = (int *)0xffffffff;
          pass_01 = pass_00;
          pPVar8 = PKCS12_decrypt_skey(bag,(char *)pass_00,-1);
          if (pPVar8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
            iVar22 = (*(code *)PTR_EVP_PKCS82PKEY_006a7220)(pPVar8);
            puVar1 = PTR_PKCS8_PRIV_KEY_INFO_free_006a722c;
            *piVar2 = iVar22;
            (*(code *)puVar1)(pPVar8);
            if (*piVar2 != 0) goto LAB_005a9560;
          }
LAB_005a95f0:
          iVar4 = 0;
          goto LAB_005a957c;
        }
      }
      else if (iVar22 < 0x98) {
        if (((iVar22 == 0x96) && (piVar2 != (int *)0x0)) && (*piVar2 == 0)) {
          iVar22 = (*(code *)PTR_EVP_PKCS82PKEY_006a7220)((bag->value).bag);
          *piVar2 = iVar22;
joined_r0x005a95e8:
          if (iVar22 == 0) goto LAB_005a95f0;
        }
      }
      else if (iVar22 == 0x98) {
        iVar22 = (*(code *)PTR_OBJ_obj2nid_006a712c)(((bag->value).bag)->type);
        if (iVar22 == 0x9e) {
          pXVar7 = PKCS12_certbag2x509(bag);
          if (pXVar7 == (X509 *)0x0) goto LAB_005a95f0;
          piVar15 = piVar14;
          if (pAVar20 == (ASN1_STRING *)0x0) {
LAB_005a964c:
            if ((pcVar21 != (char *)0x0) &&
               (piVar14 = (int *)(*(code *)PTR_ASN1_STRING_to_UTF8_006a8cf0)(&pXStack_120,pcVar21),
               -1 < (int)piVar14)) {
              pass_01 = pXStack_120;
              iVar22 = (*(code *)PTR_X509_alias_set1_006a7254)(pXVar7);
              (*(code *)PTR_CRYPTO_free_006a6e88)(pXStack_120);
              piVar15 = piVar14;
              if (iVar22 == 0) goto LAB_005a96b0;
            }
            piVar14 = piVar15;
            pass_01 = pXVar7;
            iVar22 = (*(code *)PTR_sk_push_006a6fa8)(pcVar17);
            if (iVar22 != 0) goto LAB_005a9560;
          }
          else {
            piVar14 = (int *)pAVar20->length;
            pass_01 = (X509 *)pAVar20->data;
            iVar22 = (*(code *)PTR_X509_keyid_set1_006a7284)(pXVar7);
            piVar15 = piVar14;
            if (iVar22 != 0) goto LAB_005a964c;
          }
LAB_005a96b0:
          (*(code *)PTR_X509_free_006a6e90)(pXVar7);
          iVar4 = 0;
          goto LAB_005a957c;
        }
      }
      else {
        piVar14 = piVar2;
        if (iVar22 == 0x9b) {
          pass_01 = pass_00;
          piVar18 = (int *)pcVar17;
          iVar22 = parse_bags_constprop_1((bag->value).bag);
          goto joined_r0x005a95e8;
        }
      }
LAB_005a9560:
      iVar19 = iVar19 + 1;
      iVar22 = (*(code *)PTR_sk_num_006a6e2c)(iVar4);
    } while (iVar19 < iVar22);
  }
  iVar4 = 1;
LAB_005a957c:
  if (pPStack_11c == *(PKCS12 **)puVar13) {
    return iVar4;
  }
  p12 = pPStack_11c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (p12 == (PKCS12 *)0x0) {
    uVar16 = 0x69;
    uVar11 = 0x5b;
    goto LAB_005a9b74;
  }
  if (piVar14 != (int *)0x0) {
    *piVar14 = 0;
  }
  if (piVar18 != (int *)0x0) {
    *piVar18 = 0;
  }
  if ((pass_01 == (X509 *)0x0) || (*(uchar *)&pass_01->cert_info == '\0')) {
    iVar4 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar4 == 0) {
      iVar4 = PKCS12_verify_mac(p12,"",0);
      if (iVar4 == 0) {
        uVar11 = 0x73;
        goto LAB_005a9be0;
      }
      pass_01 = (X509 *)0x638d8c;
    }
    else {
      pass_01 = (X509 *)0x0;
    }
LAB_005a97d8:
    iVar4 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar4 == 0) {
      uVar16 = 0x41;
      uVar11 = 0x7f;
LAB_005a9b74:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,uVar16,"p12_kiss.c",uVar11);
      return 0;
    }
    psVar9 = PKCS12_unpack_authsafes(p12);
    if (psVar9 != (stack_st_PKCS7 *)0x0) {
      iVar22 = 0;
LAB_005a9814:
      do {
        iVar19 = (*(code *)PTR_sk_num_006a6e2c)(psVar9);
        if (iVar19 <= iVar22) goto LAB_005a99dc;
        p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a6e24)(psVar9,iVar22);
        iVar19 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
        if (iVar19 == 0x15) {
          psVar10 = PKCS12_unpack_p7data(p7);
        }
        else {
          if (iVar19 != 0x1a) {
            iVar22 = iVar22 + 1;
            goto LAB_005a9814;
          }
          psVar10 = PKCS12_unpack_p7encdata(p7,(char *)pass_01,-1);
        }
        if (psVar10 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar9,PTR_PKCS7_free_006a723c);
          break;
        }
        iVar19 = parse_bags_constprop_1(psVar10,pass_01,piVar14,iVar4);
        if (iVar19 == 0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar10,PTR_PKCS12_SAFEBAG_free_006a7238);
          (*(code *)PTR_sk_pop_free_006a7058)(psVar9,PTR_PKCS7_free_006a723c);
          break;
        }
        iVar22 = iVar22 + 1;
        (*(code *)PTR_sk_pop_free_006a7058)();
      } while( true );
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x72,"p12_kiss.c",0x84);
  }
  else {
    iVar4 = PKCS12_verify_mac(p12,(char *)pass_01,-1);
    if (iVar4 != 0) goto LAB_005a97d8;
    uVar11 = 0x77;
LAB_005a9be0:
    iVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x71,"p12_kiss.c",uVar11);
  }
  iVar22 = 0;
  if (piVar14 == (int *)0x0) {
    if (piVar18 == (int *)0x0) goto LAB_005a9994;
    iVar19 = *piVar18;
LAB_005a996c:
    if (iVar19 != 0) {
      (*(code *)PTR_X509_free_006a6e90)();
    }
  }
  else {
LAB_005a9948:
    iVar19 = *piVar14;
LAB_005a994c:
    if (iVar19 != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)();
    }
    if (piVar18 != (int *)0x0) goto LAB_005a9968;
  }
  if (iVar22 == 0) goto LAB_005a9994;
LAB_005a9988:
  (*(code *)PTR_X509_free_006a6e90)(iVar22);
LAB_005a9994:
  if (iVar4 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a7058)(iVar4,PTR_X509_free_006a6e90);
  return 0;
LAB_005a99dc:
  (*(code *)PTR_sk_pop_free_006a7058)(psVar9,PTR_PKCS7_free_006a723c);
  if (piVar18 != (int *)0x0) {
    if (piVar14 != (int *)0x0) {
LAB_005a9a08:
      iVar22 = (*(code *)PTR_sk_pop_006a8da4)(iVar4);
      if (iVar22 != 0) {
        do {
          if ((*piVar14 != 0) && (*piVar18 == 0)) {
            (*(code *)PTR_ERR_set_mark_006a9238)();
            iVar19 = (*(code *)PTR_X509_check_private_key_006a707c)(iVar22,*piVar14);
            puVar13 = PTR_ERR_pop_to_mark_006a923c;
            if (iVar19 != 0) goto code_r0x005a9b50;
            (*(code *)PTR_ERR_pop_to_mark_006a923c)();
          }
          if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp == 0)) {
            iVar19 = *piVar14;
            goto LAB_005a994c;
          }
          iVar19 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar22);
          if (iVar19 == 0) goto LAB_005a9948;
          iVar22 = (*(code *)PTR_sk_pop_006a8da4)(iVar4);
          if (iVar22 == 0) break;
        } while( true );
      }
      goto LAB_005a9a74;
    }
    do {
      iVar22 = (*(code *)PTR_sk_pop_006a8da4)(iVar4);
      if (iVar22 == 0) goto LAB_005a9a74;
    } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp != 0)) &&
            (iVar19 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar22), iVar19 != 0));
    if (piVar18 == (int *)0x0) goto LAB_005a9988;
LAB_005a9968:
    iVar19 = *piVar18;
    goto LAB_005a996c;
  }
  if (piVar14 != (int *)0x0) {
    do {
      iVar22 = (*(code *)PTR_sk_pop_006a8da4)(iVar4);
      if (iVar22 == 0) goto LAB_005a9a74;
      if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp == 0)) {
        iVar19 = *piVar14;
        goto LAB_005a994c;
      }
      iVar19 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar22);
    } while (iVar19 != 0);
    iVar19 = *piVar14;
    goto LAB_005a994c;
  }
  do {
    iVar22 = (*(code *)PTR_sk_pop_006a8da4)(iVar4);
    if (iVar22 == 0) {
LAB_005a9a74:
      (*(code *)PTR_sk_pop_free_006a7058)(iVar4,PTR_X509_free_006a6e90);
      return 1;
    }
  } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp != 0)) &&
          (iVar19 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar22), iVar19 != 0));
  goto LAB_005a9988;
code_r0x005a9b50:
  *piVar18 = iVar22;
  (*(code *)puVar13)();
  goto LAB_005a9a08;
}

