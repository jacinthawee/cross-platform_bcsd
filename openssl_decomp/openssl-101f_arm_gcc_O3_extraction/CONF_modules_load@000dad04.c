
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
  
  local_2c = __TMC_END__;
  if (cnf != (CONF *)0x0) {
    if (appname == (char *)0x0) {
LAB_000dafe8:
      pcVar1 = NCONF_get_string(cnf,(char *)0x0,"openssl_conf");
      if (pcVar1 == (char *)0x0) {
LAB_000daffe:
        ERR_clear_error();
        goto LAB_000dadd4;
      }
    }
    else {
      pcVar1 = NCONF_get_string(cnf,(char *)0x0,appname);
      if (pcVar1 == (char *)0x0) {
        if ((int)(flags << 0x1a) < 0) goto LAB_000dafe8;
        goto LAB_000daffe;
      }
    }
    p_Var2 = (_STACK *)NCONF_get_section(cnf,pcVar1);
    if (p_Var2 == (_STACK *)0x0) goto LAB_000dadd6;
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
          if (iVar5 == 0) goto LAB_000dae82;
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
LAB_000db012:
            ERR_put_error(0xe,0x75,iVar3,"conf_mod.c",0x11d);
            ERR_add_error_data(4,"module=",__s,", path=",pcVar1);
            goto LAB_000dadb6;
          }
          pDVar7 = (DSO *)DSO_bind_func(pDVar6,"OPENSSL_init");
          if (pDVar7 == (DSO *)0x0) {
            iVar3 = 0x70;
LAB_000db00c:
            DSO_free(pDVar6);
            goto LAB_000db012;
          }
          pDVar8 = (DSO *)DSO_bind_func(pDVar6,"OPENSSL_finish");
          if (((supported_modules == (_STACK *)0x0) &&
              (supported_modules = sk_new_null(), supported_modules == (_STACK *)0x0)) ||
             (data = (DSO **)CRYPTO_malloc(0x18,"conf_mod.c",299), data == (DSO **)0x0)) {
LAB_000db00a:
            iVar3 = 0;
            goto LAB_000db00c;
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
            goto LAB_000db00a;
          }
LAB_000dae82:
          data_00 = (void **)CRYPTO_malloc(0x14,"conf_mod.c",0x163);
          if (data_00 == (void **)0x0) {
LAB_000daf26:
            if ((flags & 4) != 0) goto LAB_000dadbe;
            ERR_put_error(0xe,0x76,0x6d,"conf_mod.c",0xeb);
            BIO_snprintf(acStack_3c,0xd,"%-8d",0xffffffff);
            ERR_add_error_data(6,"module=",__s,", value=",group,", retcode=",acStack_3c);
            if ((flags & 1) != 0) goto LAB_000dadc6;
            goto LAB_000daf8a;
          }
          *data_00 = data;
          pcVar1 = BUF_strdup(__s);
          data_00[1] = pcVar1;
          pcVar1 = BUF_strdup(group);
          pvVar4 = data_00[1];
          data_00[4] = (void *)0x0;
          data_00[2] = pcVar1;
          if (pvVar4 == (void *)0x0) {
LAB_000daf1a:
            if (pcVar1 != (char *)0x0) {
              CRYPTO_free(pcVar1);
            }
            CRYPTO_free(data_00);
            goto LAB_000daf26;
          }
          if (pcVar1 == (char *)0x0) {
LAB_000daf10:
            CRYPTO_free(pvVar4);
LAB_000daf16:
            pcVar1 = (char *)data_00[2];
            goto LAB_000daf1a;
          }
          pDVar6 = data[2];
          if (pDVar6 != (DSO *)0x0) {
            iVar3 = (*(code *)pDVar6)(data_00,cnf);
            if (0 < iVar3) {
              pDVar6 = (DSO *)0x1;
              goto LAB_000daece;
            }
            pDVar7 = data[3];
            if (pDVar7 == (DSO *)0x0) goto LAB_000daf04;
LAB_000dafa0:
            (*(code *)pDVar7)(data_00);
LAB_000daf0a:
            pvVar4 = data_00[1];
            if (pvVar4 != (void *)0x0) goto LAB_000daf10;
            goto LAB_000daf16;
          }
LAB_000daece:
          if (initialized_modules == (_STACK *)0x0) {
            initialized_modules = sk_new_null();
            iVar3 = 0x17e;
            if (initialized_modules != (_STACK *)0x0) goto LAB_000daed4;
LAB_000daeec:
            ERR_put_error(0xe,0x73,0x41,"conf_mod.c",iVar3);
            pDVar7 = data[3];
            if ((pDVar7 != (DSO *)0x0) && (pDVar6 != (DSO *)0x0)) goto LAB_000dafa0;
LAB_000daf04:
            if (data_00 == (void **)0x0) goto LAB_000daf26;
            goto LAB_000daf0a;
          }
LAB_000daed4:
          iVar3 = sk_push(initialized_modules,data_00);
          if (iVar3 == 0) {
            iVar3 = 0x185;
            goto LAB_000daeec;
          }
          data[4] = (DSO *)((int)&data[4]->meth + 1);
        }
        else {
LAB_000dadb6:
          if ((flags & 4) == 0) {
            ERR_put_error(0xe,0x76,0x71,"conf_mod.c",0xde);
            ERR_add_error_data(2,"module=",__s);
          }
LAB_000dadbe:
          if ((flags & 1) == 0) {
LAB_000daf8a:
            p_Var2 = (_STACK *)0xffffffff;
            goto LAB_000dadd6;
          }
        }
LAB_000dadc6:
        iVar10 = iVar10 + 1;
        iVar3 = sk_num(p_Var2);
      } while (iVar10 < iVar3);
    }
  }
LAB_000dadd4:
  p_Var2 = (_STACK *)0x1;
LAB_000dadd6:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)p_Var2;
}

