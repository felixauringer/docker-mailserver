# Authentication for OAUTH2 users. Included from 10-auth.conf.
#
# Documentation
#   PassDB: https://doc.dovecot.org/configuration_manual/authentication/password_databases_passdb/
#   UserDB: https://doc.dovecot.org/configuration_manual/authentication/user_databases_userdb/

auth_mechanisms = $auth_mechanisms oauthbearer xoauth2
auth_debug = yes
auth_verbose = yes

# https://doc.dovecot.org/configuration_manual/authentication/oauth2/#authentication-oauth2
passdb {
  driver = oauth2
  mechanisms = xoauth2 oauthbearer
  args = /etc/dovecot/dovecot-oauth2.conf.ext
}

# https://doc.dovecot.org/configuration_manual/authentication/static_user_database/#authentication-static-user-database
userdb {
  driver = passwd-file
  args = username_format=%u /etc/dovecot/userdb
  default_fields = uid=docker gid=docker home=/var/mail/%d/%n
}

