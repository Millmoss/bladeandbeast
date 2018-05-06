using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnitCamera : MonoBehaviour
{
	public Camera playerCamera;
	public Transform cameraFocus;
	public float xSensitivity = 1;
	public float ySensitivity = -1;
	private Vector3 playerChange;
	private float xLook;
	private float yLook;
	private float rotateSpeed;
	public bool mouseLock = true;
	private bool rotateCamera = true;
	private float yRotationDif = 0;

	void Start()
	{
		transform.position = new Vector3(cameraFocus.transform.position.x, cameraFocus.transform.position.y + 1f, cameraFocus.transform.position.z - 1f);
		cameraFocus.LookAt(Camera.main.transform);
		playerCamera.transform.Rotate(Vector3.right, 45);
		playerChange = cameraFocus.transform.position;
		rotateSpeed = 20f;
		transform.RotateAround(cameraFocus.transform.position, Vector3.up, 180);
		yRotationDif = transform.rotation.eulerAngles.y - yRotationDif;
		cameraFocus.transform.Rotate(Vector3.up, yRotationDif);
		yRotationDif = transform.rotation.eulerAngles.y;
	}

	void Update()
	{
		if (Input.GetKeyUp(KeyCode.Escape) || Input.GetKeyUp(KeyCode.LeftAlt))
		{
			mouseLock = !mouseLock;
		}

		//camera move input

		if(Input.GetMouseButtonDown(1))
		{
			Cursor.visible = false;
			rotateCamera = true;
			Cursor.lockState = CursorLockMode.Confined;
		}
		if (Input.GetMouseButton(1))
		{
			xLook = xSensitivity * Input.GetAxis("Mouse X");
			yLook = ySensitivity * Input.GetAxis("Mouse Y");
		}
		else if (Input.GetMouseButtonUp(1))
		{
			Cursor.visible = true;
			rotateCamera = false;
			Cursor.lockState = CursorLockMode.None;
		}

		playerCamera.transform.eulerAngles = new Vector3(playerCamera.transform.eulerAngles.x, playerCamera.transform.eulerAngles.y, 0.0f);
		cameraFocus.LookAt(Camera.main.transform);
		cameraFocus.transform.eulerAngles = new Vector3(0.0f, cameraFocus.transform.eulerAngles.y, 0.0f);

	}

	void FixedUpdate()
	{
		if (rotateCamera)
		{
			//camera movement
			playerChange = cameraFocus.transform.position - playerChange;
			//playerChange.y = 0;
			transform.position += playerChange;

			//camera y rotation //IF ROTATION GETS WEIRD REORDER X AND Y!!!
			transform.RotateAround(cameraFocus.transform.position, Vector3.up, xLook * Time.deltaTime * rotateSpeed);
			yRotationDif = transform.rotation.eulerAngles.y - yRotationDif;
			cameraFocus.transform.Rotate(Vector3.up, yRotationDif);
			yRotationDif = transform.rotation.eulerAngles.y;

			//camera x rotation //DO NOT REORDER X AND Y!!!
			float xRotation = playerCamera.transform.rotation.eulerAngles.x;
			float futureRotation = yLook * Time.deltaTime * rotateSpeed;
			playerCamera.transform.RotateAround(cameraFocus.position, cameraFocus.right, futureRotation * -1f);
			if ((xRotation + futureRotation) >= 45 && (xRotation + futureRotation) <= 180)
			{
				playerCamera.transform.RotateAround(cameraFocus.position, cameraFocus.right, futureRotation * 1f);
			}
			else if ((xRotation + futureRotation) <= 324 && (xRotation + futureRotation) > 180)
			{
				playerCamera.transform.RotateAround(cameraFocus.position, cameraFocus.right, futureRotation * 1f);
			}

			//update player position
			playerChange = cameraFocus.position;
		}
	}

	void LateUpdate()
	{
		//movement stabilization
		playerChange = cameraFocus.position - playerChange;
		//playerChange.y = 0;
		transform.position += playerChange;
		playerChange = cameraFocus.position;
	}
}