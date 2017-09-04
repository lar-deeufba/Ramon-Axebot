
(cl:in-package :asdf)

(defsystem "ros_gui-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "RX_data" :depends-on ("_package_RX_data"))
    (:file "_package_RX_data" :depends-on ("_package"))
  ))