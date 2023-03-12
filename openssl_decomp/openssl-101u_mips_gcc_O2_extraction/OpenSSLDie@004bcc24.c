
void OpenSSLDie(char *file,int line,char *assertion)

{
  OPENSSL_showfatal("%s(%d): OpenSSL internal error, assertion failed: %s\n",file,line,assertion);
  (*(code *)PTR_abort_006a9964)();
  return;
}

