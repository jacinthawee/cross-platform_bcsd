
int X509_STORE_CTX_get_ex_new_index
              (long argl,void *argp,undefined1 *new_func,undefined1 *dup_func,undefined1 *free_func)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_get_ex_new_index_006a947c)
                    (5,argl,argp,new_func,dup_func,free_func,&_gp);
  return iVar1;
}
