(if (file-exists-p "/usr/share/emacs/site-lisp/")
    (setq config_files "/usr/share/emacs/site-lisp/")
  (setq config_files "~/.emacs.d/root-42/"))
(setq load-path (append (list nil config_files) load-path))

(load "list.el")
(load "string.el")
(load "comments.el")
(load "header.el")

(set-language-environment "UTF-8")
(setq-default line-number-mode nil)
(setq-default tab-width 4)
(setq-default indent-tabs-mode t)
(global-set-key (kbd "DEL") 'backward-delete-char)
(setq-default c-backspace-function 'backward-delete-char)
(setq-default c-basic-offset 4)
(setq-default c-default-style "linux")
(setq-default tab-stop-list '(4 8 12 16 20 24 28 32 36 40 44 \
				48 52 56 60
				64 68 72 76 80 84 88 92 96 100 104 108 112 11\
				6 120))

(if (file-exists-p "~/.emacs.d/myemacs") (load-file "~/.emacs\
.d/myemacs"))
