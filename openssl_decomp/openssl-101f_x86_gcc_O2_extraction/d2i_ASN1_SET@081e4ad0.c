
stack_st_OPENSSL_BLOCK *
d2i_ASN1_SET(stack_st_OPENSSL_BLOCK **a,uchar **pp,long length,undefined1 *d2i,free_func *free_func,
            int ex_tag,int ex_class)

{
  _STACK *st;
  void *data;
  int iVar1;
  int in_GS_OFFSET;
  bool bVar2;
  uchar *local_4c;
  int local_48;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  uchar *local_30;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((a == (stack_st_OPENSSL_BLOCK **)0x0) || (st = (_STACK *)*a, st == (_STACK *)0x0)) &&
     (st = sk_new_null(), st == (_STACK *)0x0)) {
    ERR_put_error(0xd,0x94,0x41,"a_set.c",0xb3);
    st = (_STACK *)0x0;
  }
  else {
    local_4c = *pp;
    if (length == 0) {
      local_30 = (uchar *)0x0;
    }
    else {
      local_30 = local_4c + length;
    }
    local_40 = ASN1_get_object(&local_4c,&local_34,&local_3c,&local_38,(int)local_30 - (int)local_4c
                              );
    if ((local_40 & 0x80) == 0) {
      if (local_38 == ex_class) {
        if (local_3c == ex_tag) {
          if (local_30 < local_4c + local_34) {
            ERR_put_error(0xd,0x94,0x88,"a_set.c",0xcb);
          }
          else {
            local_30 = local_4c + local_34;
            if (local_40 == 0x21) {
              local_30 = *pp + length;
              local_34 = (int)local_30 - (int)local_4c;
            }
            do {
              if (local_30 <= local_4c) {
LAB_081e4cec:
                if (a != (stack_st_OPENSSL_BLOCK **)0x0) {
                  *a = (stack_st_OPENSSL_BLOCK *)st;
                }
                *pp = local_4c;
                goto LAB_081e4ba0;
              }
              if ((local_40 & 1) == 0) {
                bVar2 = local_34 < 1;
              }
              else {
                local_48 = ASN1_const_check_infinite_end(&local_4c,local_34);
                bVar2 = local_48 != 0;
              }
              if (bVar2) goto LAB_081e4cec;
              data = (void *)(*(code *)d2i)(0,&local_4c,local_34);
              if (data == (void *)0x0) {
                ERR_put_error(0xd,0x94,0x71,"a_set.c",0xdd);
                asn1_add_error(*pp,(int)local_4c - (int)*pp);
                break;
              }
              iVar1 = sk_push(st,data);
            } while (iVar1 != 0);
          }
        }
        else {
          ERR_put_error(0xd,0x94,0x68,"a_set.c",0xc6);
        }
      }
      else {
        ERR_put_error(0xd,0x94,0x65,"a_set.c",0xc1);
      }
    }
    if ((a == (stack_st_OPENSSL_BLOCK **)0x0) || (st != (_STACK *)*a)) {
      if (free_func == (free_func *)0x0) {
        sk_free(st);
        st = (_STACK *)0x0;
      }
      else {
        sk_pop_free(st,(func *)free_func);
        st = (_STACK *)0x0;
      }
    }
    else {
      st = (_STACK *)0x0;
    }
  }
LAB_081e4ba0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (stack_st_OPENSSL_BLOCK *)st;
}

