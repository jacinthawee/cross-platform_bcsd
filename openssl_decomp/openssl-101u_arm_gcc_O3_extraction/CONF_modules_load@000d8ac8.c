
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int CONF_modules_load(CONF *cnf,char *appname,ulong flags)

{
  char *pcVar1;
  _STACK *p_Var2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  DSO *pDVar6;
  DSO *pDVar7;
  DSO *pDVar8;
  DSO **data;
  DSO *pDVar9;
  void **data_00;
  char *__s;
  size_t __n;
  char *group;
  int iVar10;
  char acStack_3c [16];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (cnf != (CONF *)0x0) {
    if (appname == (char *)0x0) {
LAB_000d8dac:
      pcVar1 = NCONF_get_string(cnf,(char *)0x0,"openssl_conf");
      if (pcVar1 == (char *)0x0) {
LAB_000d8dc2:
        ERR_clear_error();
        goto LAB_000d8b98;
      }
    }
    else {
      pcVar1 = NCONF_get_string(cnf,(char *)0x0,appname);
      if (pcVar1 == (char *)0x0) {
        if ((int)(flags << 0x1a) < 0) goto LAB_000d8dac;
        goto LAB_000d8dc2;
      }
    }
    p_Var2 = (_STACK *)NCONF_get_section(cnf,pcVar1);
    if (p_Var2 == (_STACK *)0x0) goto LAB_000d8b9a;
    iVar3 = sk_num(p_Var2);
    iVar10 = 0;
    if (0 < iVar3) {
      do {
        pvVar4 = sk_value(p_Var2,iVar10);
        __s = *(char **)((int)pvVar4 + 4);
        group = *(char **)((int)pvVar4 + 8);
        pcVar1 = strrchr(__s,0x2e);
        if (pcVar1 == (char *)0x0) {
          __n = strlen(__s);
        }
        else {
          __n = (int)pcVar1 - (int)__s;
        }
        for (iVar3 = 0; iVar5 = sk_num(supported_modules), iVar3 < iVar5; iVar3 = iVar3 + 1) {
          data = (DSO **)sk_value(supported_modules,iVar3);
          iVar5 = strncmp((char *)data[1],__s,__n);
          if (iVar5 == 0) goto LAB_000d8c46;
        }
        if ((flags & 8) == 0) {
          pcVar1 = NCONF_get_string(cnf,group,"path");
          if (pcVar1 == (char *)0x0) {
            ERR_clear_error();
            pcVar1 = __s;
          }
          pDVar6 = DSO_load((DSO *)0x0,pcVar1,(DSO_METHOD *)0x0,0);
          if (pDVar6 == (DSO *)0x0) {
            iVar3 = 0x6e;
LAB_000d8dd6:
            ERR_put_error(0xe,0x75,iVar3,"conf_mod.c",0x10f);
            ERR_add_error_data(4,"module=",__s,", path=",pcVar1);
            goto LAB_000d8b7a;
          }
          pDVar7 = (DSO *)DSO_bind_func(pDVar6,"OPENSSL_init");
          if (pDVar7 == (DSO *)0x0) {
            iVar3 = 0x70;
LAB_000d8dd0:
            DSO_free(pDVar6);
            goto LAB_000d8dd6;
          }
          pDVar8 = (DSO *)DSO_bind_func(pDVar6,"OPENSSL_finish");
          if (((supported_modules == (_STACK *)0x0) &&
              (supported_modules = sk_new_null(), supported_modules == (_STACK *)0x0)) ||
             (data = (DSO **)CRYPTO_malloc(0x18,"conf_mod.c",0x11d), data == (DSO **)0x0)) {
LAB_000d8dce:
            iVar3 = 0;
            goto LAB_000d8dd0;
          }
          *data = pDVar6;
          pDVar9 = (DSO *)BUF_strdup(__s);
          data[2] = pDVar7;
          data[3] = pDVar8;
          data[4] = (DSO *)0x0;
          data[1] = pDVar9;
          iVar3 = sk_push(supported_modules,data);
          if (iVar3 == 0) {
            CRYPTO_free(data);
            goto LAB_000d8dce;
          }
LAB_000d8c46:
          data_00 = (void **)CRYPTO_malloc(0x14,"conf_mod.c",0x154);
          if (data_00 == (void **)0x0) {
LAB_000d8cea:
            if ((flags & 4) != 0) goto LAB_000d8b82;
            ERR_put_error(0xe,0x76,0x6d,"conf_mod.c",0xdf);
            BIO_snprintf(acStack_3c,0xd,"%-8d",0xffffffff);
            ERR_add_error_data(6,"module=",__s,", value=",group,", retcode=",acStack_3c);
            if ((flags & 1) != 0) goto LAB_000d8b8a;
            goto LAB_000d8d4e;
          }
          *data_00 = data;
          pcVar1 = BUF_strdup(__s);
          data_00[1] = pcVar1;
          pcVar1 = BUF_strdup(group);
          pvVar4 = data_00[1];
          data_00[4] = (void *)0x0;
          data_00[2] = pcVar1;
          if (pvVar4 == (void *)0x0) {
LAB_000d8cde:
            if (pcVar1 != (char *)0x0) {
              CRYPTO_free(pcVar1);
            }
            CRYPTO_free(data_00);
            goto LAB_000d8cea;
          }
          if (pcVar1 == (char *)0x0) {
LAB_000d8cd4:
            CRYPTO_free(pvVar4);
LAB_000d8cda:
            pcVar1 = (char *)data_00[2];
            goto LAB_000d8cde;
          }
          pDVar6 = data[2];
          if (pDVar6 != (DSO *)0x0) {
            iVar3 = (*(code *)pDVar6)(data_00,cnf);
            if (0 < iVar3) {
              pDVar6 = (DSO *)0x1;
              goto LAB_000d8c92;
            }
            pDVar7 = data[3];
            if (pDVar7 == (DSO *)0x0) goto LAB_000d8cc8;
LAB_000d8d64:
            (*(code *)pDVar7)(data_00);
LAB_000d8cce:
            pvVar4 = data_00[1];
            if (pvVar4 != (void *)0x0) goto LAB_000d8cd4;
            goto LAB_000d8cda;
          }
LAB_000d8c92:
          if (initialized_modules == (_STACK *)0x0) {
            initialized_modules = sk_new_null();
            iVar3 = 0x16c;
            if (initialized_modules != (_STACK *)0x0) goto LAB_000d8c98;
LAB_000d8cb0:
            ERR_put_error(0xe,0x73,0x41,"conf_mod.c",iVar3);
            pDVar7 = data[3];
            if ((pDVar7 != (DSO *)0x0) && (pDVar6 != (DSO *)0x0)) goto LAB_000d8d64;
LAB_000d8cc8:
            if (data_00 == (void **)0x0) goto LAB_000d8cea;
            goto LAB_000d8cce;
          }
LAB_000d8c98:
          iVar3 = sk_push(initialized_modules,data_00);
          if (iVar3 == 0) {
            iVar3 = 0x172;
            goto LAB_000d8cb0;
          }
          data[4] = (DSO *)((int)&data[4]->meth + 1);
        }
        else {
LAB_000d8b7a:
          if ((flags & 4) == 0) {
            ERR_put_error(0xe,0x76,0x71,"conf_mod.c",0xd4);
            ERR_add_error_data(2,"module=",__s);
          }
LAB_000d8b82:
          if ((flags & 1) == 0) {
LAB_000d8d4e:
            p_Var2 = (_STACK *)0xffffffff;
            goto LAB_000d8b9a;
          }
        }
LAB_000d8b8a:
        iVar10 = iVar10 + 1;
        iVar3 = sk_num(p_Var2);
      } while (iVar10 < iVar3);
    }
  }
LAB_000d8b98:
  p_Var2 = (_STACK *)0x1;
LAB_000d8b9a:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)p_Var2;
}

