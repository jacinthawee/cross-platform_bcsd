
undefined4
args_verify(int *param_1,int *param_2,int *param_3,BIO *param_4,X509_VERIFY_PARAM **param_5)

{
  char **ppcVar1;
  char *__s1;
  ASN1_OBJECT *policy;
  undefined4 uVar2;
  X509_PURPOSE *pXVar3;
  int purpose;
  X509_VERIFY_PARAM *param;
  int iVar4;
  char **ppcVar5;
  long depth;
  ulong flags;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  bool bVar9;
  int local_34;
  int local_24;
  int local_20;
  
  iVar4 = 8;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar9 = true;
  ppcVar1 = (char **)*param_1;
  __s1 = *ppcVar1;
  pcVar7 = ppcVar1[1];
  pcVar6 = __s1;
  pcVar8 = "-policy";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (bVar9) {
    if (pcVar7 == (char *)0x0) {
      policy = (ASN1_OBJECT *)0x0;
      *param_3 = 1;
      iVar4 = 1;
      ppcVar5 = ppcVar1;
    }
    else {
      policy = OBJ_txt2obj(pcVar7,0);
      if (policy == (ASN1_OBJECT *)0x0) {
        BIO_printf(param_4,"Invalid Policy \"%s\"\n",pcVar7);
        ppcVar5 = (char **)*param_1;
        *param_3 = 1;
        iVar4 = 1;
      }
      else {
        iVar4 = *param_3;
        ppcVar5 = (char **)*param_1;
      }
    }
    local_34 = 0;
    depth = -1;
    *param_1 = (int)(ppcVar5 + 1);
    flags = 0;
LAB_0807c8a4:
    purpose = 0;
    param = *param_5;
    if (iVar4 != 0) goto LAB_0807c8b2;
LAB_0807c982:
    if (param == (X509_VERIFY_PARAM *)0x0) {
      param = X509_VERIFY_PARAM_new();
      *param_5 = param;
      if (param != (X509_VERIFY_PARAM *)0x0) goto LAB_0807c98a;
      *param_3 = 1;
      goto LAB_0807c8cc;
    }
LAB_0807c98a:
    if (policy != (ASN1_OBJECT *)0x0) {
      X509_VERIFY_PARAM_add0_policy(param,policy);
    }
    if (flags != 0) {
      X509_VERIFY_PARAM_set_flags(*param_5,flags);
    }
    if (purpose != 0) {
      X509_VERIFY_PARAM_set_purpose(*param_5,purpose);
    }
    if (-1 < depth) {
      X509_VERIFY_PARAM_set_depth(*param_5,depth);
    }
    if (local_34 == 0) goto LAB_0807c8cc;
    X509_VERIFY_PARAM_set_time(*param_5,local_34);
    iVar4 = *param_1 + 4;
    *param_1 = iVar4;
  }
  else {
    iVar4 = 9;
    pcVar6 = __s1;
    pcVar8 = "-purpose";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar9);
    if (!bVar9) {
      iVar4 = 0xe;
      pcVar6 = __s1;
      pcVar8 = "-verify_depth";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pcVar6 == *pcVar8;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      } while (bVar9);
      if (bVar9) {
        if (pcVar7 == (char *)0x0) {
          depth = -1;
          *param_3 = 1;
          iVar4 = 1;
          ppcVar5 = ppcVar1;
        }
        else {
          depth = strtol(pcVar7,(char **)0x0,10);
          if (depth < 0) {
            BIO_printf(param_4,"invalid depth\n");
            ppcVar5 = (char **)*param_1;
            *param_3 = 1;
            iVar4 = 1;
          }
          else {
            iVar4 = *param_3;
            ppcVar5 = (char **)*param_1;
          }
        }
        local_34 = 0;
        *param_1 = (int)(ppcVar5 + 1);
        flags = 0;
        policy = (ASN1_OBJECT *)0x0;
      }
      else {
        iVar4 = 8;
        pcVar6 = __s1;
        pcVar8 = "-attime";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pcVar6 == *pcVar8;
          pcVar6 = pcVar6 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          if (pcVar7 == (char *)0x0) {
            local_34 = 0;
            *param_3 = 1;
            iVar4 = 1;
            ppcVar5 = ppcVar1;
          }
          else {
            iVar4 = __isoc99_sscanf(pcVar7,&DAT_081f7634,&local_24);
            if (iVar4 == 1) {
              iVar4 = *param_3;
            }
            else {
              BIO_printf(bio_err,"Error parsing timestamp %s\n",pcVar7);
              *param_3 = 1;
              iVar4 = 1;
            }
            local_34 = local_24;
            ppcVar5 = (char **)*param_1;
          }
          depth = -1;
          *param_1 = (int)(ppcVar5 + 1);
          flags = 0;
          policy = (ASN1_OBJECT *)0x0;
        }
        else {
          iVar4 = 0x11;
          pcVar7 = __s1;
          pcVar6 = "-ignore_critical";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pcVar7 == *pcVar6;
            pcVar7 = pcVar7 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar9);
          if (bVar9) {
            local_34 = 0;
            depth = -1;
            flags = 0x10;
            policy = (ASN1_OBJECT *)0x0;
            iVar4 = *param_3;
          }
          else {
            iVar4 = 0xf;
            pcVar7 = __s1;
            pcVar6 = "-issuer_checks";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == *pcVar6;
              pcVar7 = pcVar7 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar9);
            if (bVar9) {
              local_34 = 0;
              depth = -1;
              flags = 1;
              policy = (ASN1_OBJECT *)0x0;
              iVar4 = *param_3;
            }
            else {
              iVar4 = 0xb;
              pcVar7 = __s1;
              pcVar6 = "-crl_check";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar9 = *pcVar7 == *pcVar6;
                pcVar7 = pcVar7 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar9);
              if (bVar9) {
                local_34 = 0;
                depth = -1;
                flags = 4;
                policy = (ASN1_OBJECT *)0x0;
                iVar4 = *param_3;
              }
              else {
                iVar4 = 0xf;
                pcVar7 = __s1;
                pcVar6 = "-crl_check_all";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar9 = *pcVar7 == *pcVar6;
                  pcVar7 = pcVar7 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar9);
                if (bVar9) {
                  local_34 = 0;
                  depth = -1;
                  flags = 0xc;
                  policy = (ASN1_OBJECT *)0x0;
                  iVar4 = *param_3;
                }
                else {
                  iVar4 = 0xe;
                  pcVar7 = __s1;
                  pcVar6 = "-policy_check";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar9 = *pcVar7 == *pcVar6;
                    pcVar7 = pcVar7 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar9);
                  if (bVar9) {
                    local_34 = 0;
                    depth = -1;
                    flags = 0x80;
                    policy = (ASN1_OBJECT *)0x0;
                    iVar4 = *param_3;
                  }
                  else {
                    iVar4 = 0x11;
                    pcVar7 = __s1;
                    pcVar6 = "-explicit_policy";
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar9 = *pcVar7 == *pcVar6;
                      pcVar7 = pcVar7 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar9);
                    if (bVar9) {
                      local_34 = 0;
                      depth = -1;
                      flags = 0x100;
                      policy = (ASN1_OBJECT *)0x0;
                      iVar4 = *param_3;
                    }
                    else {
                      iVar4 = 0xd;
                      pcVar7 = __s1;
                      pcVar6 = "-inhibit_any";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar9 = *pcVar7 == *pcVar6;
                        pcVar7 = pcVar7 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar9);
                      if (bVar9) {
                        local_34 = 0;
                        depth = -1;
                        flags = 0x200;
                        policy = (ASN1_OBJECT *)0x0;
                        iVar4 = *param_3;
                      }
                      else {
                        iVar4 = strcmp(__s1,"-inhibit_map");
                        if (iVar4 == 0) {
                          local_34 = 0;
                          depth = -1;
                          flags = 0x400;
                          policy = (ASN1_OBJECT *)0x0;
                          iVar4 = *param_3;
                        }
                        else {
                          iVar4 = strcmp(__s1,"-x509_strict");
                          if (iVar4 == 0) {
                            local_34 = 0;
                            depth = -1;
                            flags = 0x20;
                            policy = (ASN1_OBJECT *)0x0;
                            iVar4 = *param_3;
                          }
                          else {
                            iVar4 = strcmp(__s1,"-extended_crl");
                            if (iVar4 == 0) {
                              local_34 = 0;
                              depth = -1;
                              flags = 0x1000;
                              policy = (ASN1_OBJECT *)0x0;
                              iVar4 = *param_3;
                            }
                            else {
                              iVar4 = strcmp(__s1,"-use_deltas");
                              if (iVar4 == 0) {
                                local_34 = 0;
                                depth = -1;
                                flags = 0x2000;
                                policy = (ASN1_OBJECT *)0x0;
                                iVar4 = *param_3;
                              }
                              else {
                                iVar4 = strcmp(__s1,"-policy_print");
                                if (iVar4 == 0) {
                                  local_34 = 0;
                                  depth = -1;
                                  flags = 0x800;
                                  policy = (ASN1_OBJECT *)0x0;
                                  iVar4 = *param_3;
                                }
                                else {
                                  iVar4 = strcmp(__s1,"-check_ss_sig");
                                  uVar2 = 0;
                                  if (iVar4 != 0) goto LAB_0807c8ed;
                                  local_34 = 0;
                                  depth = -1;
                                  flags = 0x4000;
                                  policy = (ASN1_OBJECT *)0x0;
                                  iVar4 = *param_3;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_0807c8a4;
    }
    if (pcVar7 == (char *)0x0) {
      purpose = 0;
      *param_3 = 1;
      iVar4 = 1;
      ppcVar5 = ppcVar1;
    }
    else {
      iVar4 = X509_PURPOSE_get_by_sname(pcVar7);
      if (iVar4 < 0) {
        purpose = 0;
        BIO_printf(param_4,"unrecognized purpose\n");
        ppcVar5 = (char **)*param_1;
        *param_3 = 1;
        iVar4 = 1;
      }
      else {
        pXVar3 = X509_PURPOSE_get0(iVar4);
        purpose = X509_PURPOSE_get_id(pXVar3);
        iVar4 = *param_3;
        ppcVar5 = (char **)*param_1;
      }
    }
    flags = 0;
    policy = (ASN1_OBJECT *)0x0;
    *param_1 = (int)(ppcVar5 + 1);
    local_34 = 0;
    depth = -1;
    param = *param_5;
    if (iVar4 == 0) goto LAB_0807c982;
LAB_0807c8b2:
    if (param != (X509_VERIFY_PARAM *)0x0) {
      X509_VERIFY_PARAM_free(param);
    }
    *param_5 = (X509_VERIFY_PARAM *)0x0;
LAB_0807c8cc:
    iVar4 = *param_1 + 4;
    *param_1 = iVar4;
  }
  if (param_2 == (int *)0x0) {
    uVar2 = 1;
  }
  else {
    *param_2 = *param_2 - (iVar4 - (int)ppcVar1 >> 2);
    uVar2 = 1;
  }
LAB_0807c8ed:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

