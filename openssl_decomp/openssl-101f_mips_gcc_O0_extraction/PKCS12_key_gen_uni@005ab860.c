
/* WARNING: Removing unreachable block (ram,0x005ac8bc) */
/* WARNING: Removing unreachable block (ram,0x005ac874) */
/* WARNING: Removing unreachable block (ram,0x005ac8c4) */
/* WARNING: Removing unreachable block (ram,0x005ac8d8) */
/* WARNING: Removing unreachable block (ram,0x005ac87c) */
/* WARNING: Removing unreachable block (ram,0x005ac894) */
/* WARNING: Removing unreachable block (ram,0x005ac8a0) */
/* WARNING: Removing unreachable block (ram,0x005ac8f8) */
/* WARNING: Removing unreachable block (ram,0x005ac8ac) */
/* WARNING: Removing unreachable block (ram,0x005ac8b0) */
/* WARNING: Removing unreachable block (ram,0x005ac908) */
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
  X509 *pXStack_144;
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
  local_60 = (uchar **)PTR___stack_chk_guard_006aabf0;
  local_54 = out;
  local_80 = &_gp;
  local_2c = *(uchar **)PTR___stack_chk_guard_006aabf0;
  iVar4 = passlen;
  piStack_10c = (int *)saltlen;
  local_74 = pass;
  local_70 = salt;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_b0);
  iStack_ac = (**(code **)(local_80 + -0x6900))(md_type);
  piVar2 = (int *)(**(code **)(local_80 + -0x6fb4))(md_type);
  if ((int)piVar2 < 0) {
    iVar22 = 0;
  }
  else {
    local_5c = "r";
    local_68 = (**(code **)(local_80 + -0x7dd8))(iStack_ac,s_p12_key_c_00670654,0x8a);
    unaff_s2 = (**(code **)(local_80 + -0x7dd8))(piVar2,s_p12_key_c_00670654,0x8b);
    local_6c = (undefined *)
               (**(code **)(local_80 + -0x7dd8))(iStack_ac + 1,s_p12_key_c_00670654,0x8c);
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
    unaff_s5 = (uchar *)(**(code **)(local_80 + -0x7dd8))(local_58,local_5c + 0x654,0x91);
    unaff_s7 = (**(code **)(local_80 + -0x7c2c))();
    local_64 = (**(code **)(local_80 + -0x7c2c))();
    if ((((local_68 != 0) && (unaff_s2 != 0)) && (local_6c != (undefined *)0x0)) &&
       (((unaff_s5 != (uchar *)0x0 && (unaff_s7 != 0)) && (local_64 != 0)))) {
      if (0 < iStack_ac) {
        (**(code **)(local_80 + -0x53e0))(local_68,id & 0xff,iStack_ac);
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
      while (((iVar4 = (**(code **)(local_80 + -0x7870))(puStack_b0,md_type,0), iVar4 != 0 &&
              (iVar4 = (**(code **)(local_80 + -0x786c))(puStack_b0,local_68,iStack_ac), iVar4 != 0)
              ) && ((iVar4 = (**(code **)(local_80 + -0x786c))(puStack_b0,unaff_s5,local_58),
                    iVar4 != 0 &&
                    (iVar4 = (**(code **)(local_80 + -0x7868))(puStack_b0,unaff_s2,0), iVar4 != 0)))
             )) {
        passlen = 1;
        if (saltlen == 0) {
          do {
            iVar4 = (**(code **)(local_80 + -0x7870))(puStack_b0,md_type,0);
            if (((iVar4 == 0) ||
                (iVar4 = (**(code **)(local_80 + -0x786c))(puStack_b0,unaff_s2,piVar2), iVar4 == 0))
               || (iVar4 = (**(code **)(local_80 + -0x7868))(puStack_b0,unaff_s2,0), iVar4 == 0))
            goto LAB_005abba4;
            passlen = passlen + 1;
          } while (iter != passlen);
        }
        passlen = (int)((int)piVar2 < n);
        salt = (uchar *)n;
        if ((uchar *)passlen != (uchar *)0x0) {
          salt = (uchar *)piVar2;
        }
        iVar4 = unaff_s2;
        (**(code **)(local_80 + -0x52ec))(local_54);
        if ((uchar *)passlen == (uchar *)0x0) {
          iVar22 = 1;
          goto LAB_005abbcc;
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
        iVar4 = (**(code **)(local_80 + -0x74f0))(local_6c,iStack_ac,local_64);
        if ((iVar4 == 0) || (iVar4 = (**(code **)(local_80 + -0x7d24))(local_64,1), iVar4 == 0))
        break;
        passlen = (int)unaff_s5;
        if (0 < local_58) {
          do {
            iVar4 = (**(code **)(local_80 + -0x74f0))(passlen,iStack_ac,unaff_s7);
            if (((iVar4 == 0) ||
                (iVar4 = (**(code **)(local_80 + -0x6818))(unaff_s7,unaff_s7,local_64), iVar4 == 0))
               || (iVar4 = (**(code **)(local_80 + -0x7be0))(unaff_s7,local_6c), iVar4 == 0))
            goto LAB_005abba4;
            iVar22 = (**(code **)(local_80 + -0x7bec))(unaff_s7);
            iVar4 = iVar22 + 7;
            if (iVar22 + 7 < 0) {
              iVar4 = iVar22 + 0xe;
            }
            iVar4 = iVar4 >> 3;
            if (iStack_ac < iVar4) {
              iVar4 = (**(code **)(local_80 + -0x7be0))(unaff_s7,local_6c);
              if (iVar4 == 0) goto LAB_005abba4;
              (**(code **)(local_80 + -0x52ec))(passlen,local_70,iStack_ac);
            }
            else {
              if (iVar4 < iStack_ac) {
                local_50 = iVar4;
                (**(code **)(local_80 + -0x53e0))(passlen,0,iStack_ac - iVar4);
                iVar4 = (**(code **)(local_80 + -0x7be0))
                                  (unaff_s7,unaff_s5 + ((int)(local_74 + passlen) - local_50));
              }
              else {
                iVar4 = (**(code **)(local_80 + -0x7be0))(unaff_s7,passlen);
              }
              if (iVar4 == 0) goto LAB_005abba4;
            }
            passlen = passlen + iStack_ac;
          } while (passlen - (int)unaff_s5 < local_58);
        }
        n = n - (int)piVar2;
        local_54 = local_54 + (int)piVar2;
      }
    }
LAB_005abba4:
    salt = &DAT_00000041;
    iVar4 = 0x6f;
    piStack_10c = (int *)(local_5c + 0x654);
    iVar22 = 0;
    local_88 = 0xd1;
    (**(code **)(local_80 + -0x6eb0))(0x23);
LAB_005abbcc:
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
  (**(code **)(local_80 + -0x5328))();
  puStack_114 = PTR___stack_chk_guard_006aabf0;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_a8 = unaff_s2;
  puStack_a4 = (uchar *)passlen;
  piStack_a0 = unaff_s4;
  if (puVar12 == (uchar *)0x0) {
    puStack_bc = (uchar *)0x0;
    pXStack_b8 = (X509 *)0x0;
LAB_005abf10:
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
        (*(code *)PTR_OPENSSL_cleanse_006a8174)();
        (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_bc);
        piVar2 = (int *)salt;
      }
    }
  }
  else {
    puVar5 = OPENSSL_asc2uni((char *)puVar12,iVar4,&puStack_bc,(int *)&pXStack_b8);
    puVar12 = puStack_bc;
    if (puVar5 != (uchar *)0x0) goto LAB_005abf10;
    piVar2 = (int *)&DAT_00000041;
    pcVar17 = s_p12_key_c_00670654;
    pass_00 = (X509 *)&DAT_0000006e;
    (*(code *)PTR_ERR_put_error_006a9030)(0x23);
    piVar14 = (int *)0x0;
    piStack_118 = (int *)salt;
  }
  if (iStack_b4 == *(int *)puStack_114) {
    return (int)piVar14;
  }
  uStack_f4 = 0x5abff4;
  iVar4 = iStack_b4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar13 = PTR___stack_chk_guard_006aabf0;
  puStack_110 = puStack_7c;
  pEStack_108 = pEStack_78;
  iVar19 = 0;
  pEStack_100 = md_type;
  pPStack_11c = *(PKCS12 **)PTR___stack_chk_guard_006aabf0;
  pXStack_144 = pass_00;
  piVar14 = piVar2;
  piVar18 = (int *)pcVar17;
  puStack_104 = unaff_s5;
  iStack_fc = unaff_s7;
  uStack_f8 = saltlen;
  iVar22 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
  if (0 < iVar22) {
    do {
      bag = (PKCS12_SAFEBAG *)(*(code *)PTR_sk_value_006a7f24)(iVar4,iVar19);
      pAVar6 = PKCS12_get_attr_gen(bag->attrib,0x9c);
      if (pAVar6 == (ASN1_TYPE *)0x0) {
        pcVar21 = (char *)0x0;
      }
      else {
        pcVar21 = (pAVar6->value).ptr;
      }
      pXStack_144 = (X509 *)&DAT_0000009d;
      pAVar6 = PKCS12_get_attr_gen(bag->attrib,0x9d);
      if (pAVar6 == (ASN1_TYPE *)0x0) {
        pAVar20 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar20 = (pAVar6->value).asn1_string;
      }
      iVar22 = (*(code *)PTR_OBJ_obj2nid_006a822c)(bag->type);
      if (iVar22 == 0x97) {
        if ((piVar2 != (int *)0x0) && (*piVar2 == 0)) {
          piVar14 = (int *)0xffffffff;
          pXStack_144 = pass_00;
          pPVar8 = PKCS12_decrypt_skey(bag,(char *)pass_00,-1);
          if (pPVar8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
            iVar22 = (*(code *)PTR_EVP_PKCS82PKEY_006a8334)(pPVar8);
            puVar1 = PTR_PKCS8_PRIV_KEY_INFO_free_006a8340;
            *piVar2 = iVar22;
            (*(code *)puVar1)(pPVar8);
            if (*piVar2 != 0) goto LAB_005ac120;
          }
LAB_005ac1b0:
          iVar4 = 0;
          goto LAB_005ac13c;
        }
      }
      else if (iVar22 < 0x98) {
        if (((iVar22 == 0x96) && (piVar2 != (int *)0x0)) && (*piVar2 == 0)) {
          iVar22 = (*(code *)PTR_EVP_PKCS82PKEY_006a8334)((bag->value).bag);
          *piVar2 = iVar22;
joined_r0x005ac1a8:
          if (iVar22 == 0) goto LAB_005ac1b0;
        }
      }
      else if (iVar22 == 0x98) {
        iVar22 = (*(code *)PTR_OBJ_obj2nid_006a822c)(((bag->value).bag)->type);
        if (iVar22 == 0x9e) {
          pXVar7 = PKCS12_certbag2x509(bag);
          if (pXVar7 == (X509 *)0x0) goto LAB_005ac1b0;
          piVar15 = piVar14;
          if (pAVar20 == (ASN1_STRING *)0x0) {
LAB_005ac20c:
            if ((pcVar21 != (char *)0x0) &&
               (piVar14 = (int *)(*(code *)PTR_ASN1_STRING_to_UTF8_006a9e10)(&pXStack_120,pcVar21),
               0 < (int)piVar14)) {
              pXStack_144 = pXStack_120;
              iVar22 = (*(code *)PTR_X509_alias_set1_006a8368)(pXVar7);
              (*(code *)PTR_CRYPTO_free_006a7f88)(pXStack_120);
              piVar15 = piVar14;
              if (iVar22 == 0) goto LAB_005ac270;
            }
            piVar14 = piVar15;
            pXStack_144 = pXVar7;
            iVar22 = (*(code *)PTR_sk_push_006a80a8)(pcVar17);
            if (iVar22 != 0) goto LAB_005ac120;
          }
          else {
            piVar14 = (int *)pAVar20->length;
            pXStack_144 = (X509 *)pAVar20->data;
            iVar22 = (*(code *)PTR_X509_keyid_set1_006a8394)(pXVar7);
            piVar15 = piVar14;
            if (iVar22 != 0) goto LAB_005ac20c;
          }
LAB_005ac270:
          (*(code *)PTR_X509_free_006a7f90)(pXVar7);
          iVar4 = 0;
          goto LAB_005ac13c;
        }
      }
      else {
        piVar14 = piVar2;
        if (iVar22 == 0x9b) {
          pXStack_144 = pass_00;
          piVar18 = (int *)pcVar17;
          iVar22 = parse_bags_constprop_1((bag->value).bag);
          goto joined_r0x005ac1a8;
        }
      }
LAB_005ac120:
      iVar19 = iVar19 + 1;
      iVar22 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
    } while (iVar19 < iVar22);
  }
  iVar4 = 1;
LAB_005ac13c:
  if (pPStack_11c == *(PKCS12 **)puVar13) {
    return iVar4;
  }
  p12 = pPStack_11c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (p12 == (PKCS12 *)0x0) {
    uVar16 = 0x69;
    uVar11 = 0x59;
    goto LAB_005ac758;
  }
  if (piVar14 != (int *)0x0) {
    *piVar14 = 0;
  }
  if (piVar18 != (int *)0x0) {
    *piVar18 = 0;
  }
  if ((pXStack_144 == (X509 *)0x0) || (*(uchar *)&pXStack_144->cert_info == '\0')) {
    iVar4 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar4 == 0) {
      iVar4 = PKCS12_verify_mac(p12,"",0);
      if (iVar4 == 0) {
        uVar11 = 0x6e;
        goto LAB_005ac7c4;
      }
      pXStack_144 = (X509 *)0x6395d0;
    }
    else {
      pXStack_144 = (X509 *)0x0;
    }
LAB_005ac3a0:
    iVar4 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (iVar4 == 0) {
      uVar16 = 0x41;
      uVar11 = 0x7b;
LAB_005ac758:
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,uVar16,"p12_kiss.c",uVar11);
      return 0;
    }
    psVar9 = PKCS12_unpack_authsafes(p12);
    if (psVar9 != (stack_st_PKCS7 *)0x0) {
      iVar22 = 0;
LAB_005ac3dc:
      do {
        iVar19 = (*(code *)PTR_sk_num_006a7f2c)(psVar9);
        if (iVar19 <= iVar22) goto LAB_005ac5b0;
        p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a7f24)(psVar9,iVar22);
        iVar19 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
        if (iVar19 == 0x15) {
          psVar10 = PKCS12_unpack_p7data(p7);
        }
        else {
          if (iVar19 != 0x1a) {
            iVar22 = iVar22 + 1;
            goto LAB_005ac3dc;
          }
          psVar10 = PKCS12_unpack_p7encdata(p7,(char *)pXStack_144,-1);
        }
        if (psVar10 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_PKCS7_free_006a8350);
          break;
        }
        iVar19 = parse_bags_constprop_1(psVar10,pXStack_144,piVar14,iVar4);
        if (iVar19 == 0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar10,PTR_PKCS12_SAFEBAG_free_006a834c);
          (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_PKCS7_free_006a8350);
          break;
        }
        iVar22 = iVar22 + 1;
        (*(code *)PTR_sk_pop_free_006a8158)();
      } while( true );
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x72,"p12_kiss.c",0x81);
  }
  else {
    iVar4 = PKCS12_verify_mac(p12,(char *)pXStack_144,-1);
    if (iVar4 != 0) goto LAB_005ac3a0;
    uVar11 = 0x72;
LAB_005ac7c4:
    iVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x71,"p12_kiss.c",uVar11);
  }
  iVar22 = 0;
  if (piVar14 == (int *)0x0) {
    if (piVar18 == (int *)0x0) goto LAB_005ac568;
    iVar19 = *piVar18;
LAB_005ac540:
    if (iVar19 != 0) {
      (*(code *)PTR_X509_free_006a7f90)();
    }
  }
  else {
LAB_005ac51c:
    iVar19 = *piVar14;
LAB_005ac520:
    if (iVar19 != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a7f78)();
    }
    if (piVar18 != (int *)0x0) {
LAB_005ac53c:
      iVar19 = *piVar18;
      goto LAB_005ac540;
    }
  }
  if (iVar22 == 0) goto LAB_005ac568;
LAB_005ac55c:
  (*(code *)PTR_X509_free_006a7f90)(iVar22);
LAB_005ac568:
  if (iVar4 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a8158)(iVar4,PTR_X509_free_006a7f90);
  return 0;
LAB_005ac5b0:
  (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_PKCS7_free_006a8350);
  if (piVar14 != (int *)0x0) {
    if (piVar18 != (int *)0x0) {
      while (iVar22 = (*(code *)PTR_sk_pop_006a9ec4)(iVar4), iVar22 != 0) {
        while (((*piVar14 == 0 || (*piVar18 != 0)) ||
               (iVar19 = (*(code *)PTR_X509_check_private_key_006a817c)(iVar22), iVar19 == 0))) {
          if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp == 0)) {
            iVar19 = *piVar14;
            goto LAB_005ac520;
          }
          iVar19 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar22);
          if (iVar19 == 0) goto LAB_005ac51c;
          iVar22 = (*(code *)PTR_sk_pop_006a9ec4)(iVar4);
          if (iVar22 == 0) goto LAB_005ac640;
        }
        *piVar18 = iVar22;
      }
LAB_005ac640:
      (*(code *)PTR_sk_pop_free_006a8158)(iVar4,PTR_X509_free_006a7f90);
      return 1;
    }
    do {
      iVar22 = (*(code *)PTR_sk_pop_006a9ec4)(iVar4);
      if (iVar22 == 0) goto LAB_005ac640;
      if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp == 0)) {
        iVar19 = *piVar14;
        goto LAB_005ac520;
      }
      iVar19 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar22);
    } while (iVar19 != 0);
    iVar19 = *piVar14;
    goto LAB_005ac520;
  }
  do {
    iVar22 = (*(code *)PTR_sk_pop_006a9ec4)(iVar4);
    if (iVar22 == 0) goto LAB_005ac640;
  } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp != 0)) &&
          (iVar19 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar22), iVar19 != 0));
  if (piVar18 != (int *)0x0) goto LAB_005ac53c;
  goto LAB_005ac55c;
}

